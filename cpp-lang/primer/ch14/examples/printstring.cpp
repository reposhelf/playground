#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::ostream;
using std::string;

class PrintString
{
public:
    PrintString(ostream &o = cout, char c = ' ')
        : os(o), sep(c) {}
    void operator()(const string &s) const { os << s << sep; }

private:
    ostream &os;
    char sep;
};

int main()
{
    PrintString printer;
    printer("Hello");
    PrintString errors(cerr, '\n');
    errors("By");
    return 0;
}
