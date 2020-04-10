#ifndef VIEW_H
#define VIEW_H

class View
{
public:
    View() = default;
    View(const View&) = delete;
    View& operator=(const View&) = delete;
    virtual ~View() = default;
    void display();
protected:
    virtual void doDisplay();
private:
    void setFocus();
    void resetFocus();
};

#endif // VIEW_H
