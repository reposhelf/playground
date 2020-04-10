#include "windowmanager.h"
#include "screen.h"

WindowManager::WindowManager()
{
    _screens.push_back(Screen(80, 24, ' '));
}

void WindowManager::clear(ScreenIndex index)
{
    Screen &s = _screens[index];
    s._contents = std::string(s._height * s._width, ' ');
}
