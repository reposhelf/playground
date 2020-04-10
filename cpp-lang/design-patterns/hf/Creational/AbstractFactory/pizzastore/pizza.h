#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <list>

class PizzaIngredientFactory;
class Dough;
class Sauce;
class Cheese;
class Pepperoni;
class Clam;
class Veggie;
class Pizza
{
public:
    Pizza(PizzaIngredientFactory *ingredientFctory);
    virtual ~Pizza();

    std::string name() const { return _name; }
    void setName(const std::string &name);

    Dough *dough() const { return _dough; }
    void setDough(Dough *dough);

    Sauce *sauce() const { return _sauce; }
    void setSauce(Sauce *sauce);

    Cheese *cheese() const { return _cheese; }
    void setCheese(Cheese *cheese);

    Pepperoni *pepperoni() const { return _pepperoni; }
    void setPepperoni(Pepperoni *pepperoni);

    Clam *clam() const { return _clam; }
    void setClam(Clam *clam);

    std::list<Veggie *> veggies() const { return _veggies; }
    void setVeggies(const std::list<Veggie *> &veggies);

    virtual void prepare() = 0;
    virtual void bake() const;
    virtual void cut() const;
    virtual void box() const;

protected:
    PizzaIngredientFactory *_ingredientFactory;

private:
    std::string _name;
    Dough *_dough;
    Sauce *_sauce;
    Cheese *_cheese;
    Pepperoni *_pepperoni;
    Clam *_clam;
    std::list<Veggie *> _veggies;
};

class CheesePizza : public Pizza
{
public:
    CheesePizza(PizzaIngredientFactory *ingredientFactory);
    ~CheesePizza();

    void prepare();
};

class ClamPizza : public Pizza
{
public:
    ClamPizza(PizzaIngredientFactory *ingredientFactory);
    ~ClamPizza();

    void prepare();
};

class VeggiePizza : public Pizza
{
public:
    VeggiePizza(PizzaIngredientFactory *ingredientFactory);
    ~VeggiePizza();

    void prepare();
};

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza(PizzaIngredientFactory *ingredientFactory);
    ~PepperoniPizza();

    void prepare();
};

#endif // PIZZA_H
