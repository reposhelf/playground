#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <vector>

class Screen;
class WindowManager
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;

    WindowManager();

    void clear(ScreenIndex index);

private:
    std::vector<Screen> _screens;
};

#endif
