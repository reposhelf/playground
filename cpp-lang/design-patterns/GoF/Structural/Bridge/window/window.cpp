#include "window.h"

#include "windowimp.h"
#include "windowsystemfactory.h"

Window::Window(ViewPtr contents)
    : m_contents(contents),
      m_imp(WindowSystemFactory::instance()->makeWindowImp())
{

}

void Window::drawContents()
{
    // Empty
}

void Window::open()
{
    // Empty
}

void Window::close()
{
    // Empty
}

void Window::iconify()
{
    // Empty
}

void Window::deiconify()
{
    // Empty
}

void Window::setOrigin(const Point &)
{
    // Empty
}

void Window::setExtent(const Point &)
{
    // Empty
}

void Window::raise()
{
    // Empty
}

void Window::lower()
{
    // Empty
}

void Window::drawLine(const Point &, const Point &)
{
    // Empty
}

void Window::drawRect(const Point &x, const Point &y)
{
    if (m_imp == nullptr)
        return;

    m_imp->deviceRect(x.first, x.second, y.first, y.second);
}

void Window::drawPolygon(const Point[], int)
{
    // Empty
}

void Window::drawText(const char *, const Point &)
{
    // Empty
}

ViewPtr Window::view() const
{
    return m_contents;
}

WindowImpPtr Window::windowImp() const
{
    return m_imp;
}
