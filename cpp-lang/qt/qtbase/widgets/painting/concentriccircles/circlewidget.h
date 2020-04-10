#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H

#include <QWidget>

class CircleWidget : public QWidget
{
    Q_OBJECT

public:
    CircleWidget(QWidget *parent = Q_NULLPTR);

    void setFloatBased(bool floatBased);
    void setAntialised(bool antialised);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    void nextAnimationFrame();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    bool m_floatBased;
    bool m_antialised;
    int m_frameNo;
};

#endif // CIRCLEWIDGET_H
