#ifndef SCREEN_H
#define SCREEN_H

#include "windowmanager.h"

#include <string>
#include <iostream>

class Screen
{
public:
    typedef std::string::size_type pos;    

    Screen() = default;
    Screen(pos width, pos height, char ch);

    Screen &set(char ch);
    Screen &set(pos row, pos column, char ch);
    char get() const { return _contents[_cursor]; }
    char get(pos row, pos column) const;
    Screen &move(pos row, pos column);
    Screen &display(std::ostream &os);
    const Screen &display(std::ostream &os) const;
    pos size() const;

private:
    void doDisplay(std::ostream &os) const { os << _contents; }

    pos _cursor = 0;
    pos _width = 0;
    pos _height = 0;
    std::string _contents;

    friend void WindowManager::clear(ScreenIndex index);
};

#endif
