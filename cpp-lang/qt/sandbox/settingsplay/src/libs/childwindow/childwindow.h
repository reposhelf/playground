#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include "childwindow_global.h"

#include <QWidget>

class QLineEdit;
class CHILDWINDOWSHARED_EXPORT ChildWindow : public QWidget
{
    Q_OBJECT

public:
    static ChildWindow *getChildWindow(QWidget *parent);

protected:
    void closeEvent(QCloseEvent *event);

private:
    QLineEdit *m_lineEdit;

    ChildWindow(QWidget *parent = Q_NULLPTR);
    ChildWindow(const ChildWindow &);
    ChildWindow &operator=(const ChildWindow &);
    ~ChildWindow();

    void readSettings();
};

#endif // CHILDWINDOW_H
