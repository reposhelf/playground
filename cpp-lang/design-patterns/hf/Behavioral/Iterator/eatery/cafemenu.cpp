#include "cafemenu.h"
#include "menuitem.h"
#include "cafemenuiterator.h"

using std::shared_ptr;

CafeMenu::CafeMenu()
    : Menu(),
      _items()
{
    _items.push_back(new MenuItem("Veggie Burger and Air Fries",
                                  "Veggie burger on a whole weat bun, lettuce, tomato, and fries",
                                  true,
                                  3.99));
    _items.push_back(new MenuItem("Soup of the day",
                                  "A cup of the soup of the day, with a side salad",
                                  false,
                                  3.69));
    _items.push_back(new MenuItem("Burrito",
                                  "A large burrito, with whole pinto beans, salsa, guacamole",
                                  false,
                                  4.29));
}

CafeMenu::~CafeMenu()
{
    for (auto i : _items)
        delete i;
}

std::shared_ptr<Iterator> CafeMenu::createIterator()
{
    return shared_ptr<Iterator>(new CafeMenuIterator(_items));
}

std::string CafeMenu::title() const
{
    return "\nDINNER";
}
