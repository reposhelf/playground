/*
 * Exercise 4.37: Rewrite each of the following old-style casts to use a named cast
 */
#include <string>
using std::string;

int main()
{
    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;

    pv = static_cast<void *>(const_cast<string *>(ps)); // pv = (void*)ps;

    i = static_cast<int>(*pc); // i = int(*pc);

    pv = static_cast<void *>(&d); // pv = &d;

    pc = static_cast<char *>(pv); // pc = (char*)pv;

    return 0;
}
