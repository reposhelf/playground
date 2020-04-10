#include <iostream>
#include <string>

using namespace std;

class base
{
public:
    string name() const
    {
        cout << typeid(*this).name() << "::" << __func__ << endl;
        return basename;
    }
    virtual void print(ostream &os)
    {
        cout << typeid(*this).name() << "::" << __func__ << endl;
        os << basename;
    }

private:
    string basename = "basename";
};

class derived : public base
{
public:
    void print(ostream &os)
    {
        cout << typeid(*this).name() << "::" << __func__ << endl;
        base:: print(os);
        os << " " << i;
    }

private:
    int i;
};

int main()
{
    base bobj;
    derived dobj;

    base *bp1 = &bobj;
    base *bp2 = &dobj;

    base &br1 = bobj;
    base &br2 = dobj;

    bobj.print(cout);
    dobj.print(cout);

    bp1->name();
    bp2->name();

    br1.print(cout);
    br2.print(cout);

    return 0;
}
