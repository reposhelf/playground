#include "dinermenu.h"
#include "pancakehousemenu.h"
#include "cafemenu.h"
#include "waitress.h"

#include <vector>
using std::vector;

int main()
{
    vector<Menu *> menus;
    menus.push_back(new PancakeHouseMenu);
    menus.push_back(new DinerMenu);
    menus.push_back(new CafeMenu);

    Waitress alise(menus);
    alise.printMenu();

    for (auto m : menus)
        delete m;

    return 0;
}
