#ifndef WINDOW_H
#define WINDOW_H

#include <memory>

class View;
class WindowImp;

using ViewPtr = std::shared_ptr<View>;
using WindowImpPtr = std::shared_ptr<WindowImp>;
using Point = std::pair<int, int>;

class Window
{
public:
    explicit Window(ViewPtr contents);

    // requets which handled by Window
    virtual void drawContents();

    virtual void open();
    virtual void close();
    virtual void iconify();
    virtual void deiconify();

    // requests which redirected to WindowImp
    virtual void setOrigin(const Point&);
    virtual void setExtent(const Point&);
    virtual void raise();
    virtual void lower();

    virtual void drawLine(const Point&, const Point&);
    virtual void drawRect(const Point&, const Point&);
    virtual void drawPolygon(const Point[], int);
    virtual void drawText(const char*, const Point&);

protected:
    ViewPtr view() const;
    WindowImpPtr windowImp() const;

private:
    ViewPtr m_contents;
    WindowImpPtr m_imp;
};

#endif // WINDOW_H
