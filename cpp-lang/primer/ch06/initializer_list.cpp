#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <initializer_list>
using std::initializer_list;

void show_msg(initializer_list<string> il)
{
    for (const auto &elem : il)
        cout << elem << " ";
    cout << endl;
}

int main()
{
    show_msg( {"hello", "world"} );
    show_msg( {"hello", "my", "little", "friend"} );
    return 0;
}