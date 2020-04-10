#ifndef CHOCOLATEBOILER_H
#define CHOCOLATEBOILER_H

class ChocolateBoiler
{
public:
    static void fill();
    static void boil();
    static void drain();

private:
    ChocolateBoiler();
    ChocolateBoiler(const ChocolateBoiler &);
    ChocolateBoiler &operator=(const ChocolateBoiler &);
    ~ChocolateBoiler();

    static ChocolateBoiler *instance();

    bool m_isEmpty;
    bool m_isBoiled;
};

#endif // CHOCOLATEBOILER_H
