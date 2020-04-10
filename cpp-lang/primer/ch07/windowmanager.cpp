#include "windowmanager.h"

void WindowManager::clear(ScreenIndex index)
{
    Screen &s = _screens[index];
    s._contents = std::string(s._height * s._width, ' ');
}

WindowManager::ScreenIndex WindowManager::addScreen(const Screen &screen)
{
    _screens.push_back(screen);
    return _screens.size() - 1;
}
