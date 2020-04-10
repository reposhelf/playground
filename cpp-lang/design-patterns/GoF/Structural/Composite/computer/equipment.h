#ifndef EQUIPMENT_H
#define EQUIPMENT_H

class Equipment {
public:
    virtual ~Equipment();

    const char *name() const { return name_; }

    virtual double power() { return power_; }
    virtual double net_price() { return net_price_; }
    virtual double discount_price() { return discount_price_; }

    void set_power(double power) { power_ = power; }
    void set_net_price(double net_price) { net_price_ = net_price; }
    void set_discount_price(double discount_price) { discount_price_ = discount_price; }

    virtual void add(Equipment *equipment);
    virtual void remove(Equipment *equipment);

protected:
    Equipment(const char *name);

private:
    const char *name_;
    double power_;
    double net_price_;
    double discount_price_;
};

#endif
