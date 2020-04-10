#ifndef GRADIENTEDITOR_H
#define GRADIENTEDITOR_H

#include <QWidget>

class ShadeWidget;
class GradientEditor : public QWidget
{
    Q_OBJECT

public:
    GradientEditor(QWidget *parent = Q_NULLPTR);

    void setGradientStops(const QGradientStops &stops);

public slots:
    void updatePoints();

signals:
    void gradientStopsChanged(const QGradientStops &stops);

private:
    ShadeWidget *m_redShade;
    ShadeWidget *m_greenShade;
    ShadeWidget *m_blueShade;
    ShadeWidget *m_alphaShade;
};

#endif // GRADIENTEDITOR_H
