typedef double wages; // 'wages' is alias of 'double'
typedef wages base, *p; // 'base' is alias of 'double', 'p' is alias of 'double*'

// C++11
using Integer = int; // 'Integer' is alias of 'int'

// pointers, constants and type alias
typedef char *pstring; // 'pstring' is alias of 'char*'

int main()
{
    Integer hourCount = 40;
    wages hourly = 10.0;
    wages weekly = hourly * hourCount;

    const pstring cstr = 0; // 'cstr' is 'char *const'
    const pstring *ppcstr; // 'ppcstr' is pointer to 'char *const'

    return 0;
}