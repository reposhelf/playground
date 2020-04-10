#include "screen.h"

#include <iostream>

void solution_7_27()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
}

int main()
{
    solution_7_27();
    return 0;
}
