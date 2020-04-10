#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <list>

class Pizza
{
public:
    Pizza();
    virtual ~Pizza();

    std::string name() const { return _name; }
    void setName(const std::string &);

    std::string dought() const { return _dought; }
    void setDought(const std::string &);

    std::string sauce() const { return _sauce; }
    void setSauce(const std::string &);

    std::list<std::string> toppings() const { return _toppings; }
    void setToppings(const std::list<std::string> &);
    void addTopping(const std::string &);

    virtual void prepare() const;
    virtual void bake() const;
    virtual void cut() const;
    virtual void box() const;

protected:
    virtual void initialize() = 0;

private:
    std::string _name;
    std::string _dought;
    std::string _sauce;
    std::list<std::string> _toppings;
};

#endif // PIZZA_H
