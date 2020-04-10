#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "screen.h"

#include <vector>

class WindowManager
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;

    void clear(ScreenIndex index);
    ScreenIndex addScreen(const Screen &screen);

private:
    std::vector<Screen> _screens{Screen(80, 24, ' ')};
};

#endif
