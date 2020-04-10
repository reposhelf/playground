#include "screen.h"

Screen::Screen(pos width, pos height, char ch)
    : _width(width),
      _height(height),
      _contents(width * height, ch)
{
}


Screen &Screen::set(char ch)
{
    _contents[_cursor] = ch;
    return *this;
}

Screen &Screen::set(pos row, pos column, char ch)
{
    _contents[row * _width + column] = ch;
    return *this;
}

char Screen::get(pos row, pos column) const
{
    pos r = row * _width;
    return _contents[r + column];
}

Screen &Screen::move(pos row, pos column)
{
    pos r = row * _width;
    _cursor = r + column;
    return *this;
}

Screen &Screen::display(std::ostream &os)
{
    doDisplay(os);
    return *this;
}

const Screen &Screen::display(std::ostream &os) const
{
    doDisplay(os);
    return *this;
}

