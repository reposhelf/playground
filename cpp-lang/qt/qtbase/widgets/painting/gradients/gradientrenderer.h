#ifndef GRADIENTRENDERER_H
#define GRADIENTRENDERER_H

#include "arthurwidgets.h"

class HoverPoints;
class GradientRenderer : public ArthurFrame
{
    Q_OBJECT

public:
    GradientRenderer(QWidget *parent = Q_NULLPTR);

    QSize sizeHint() const Q_DECL_OVERRIDE { return QSize(400, 400); }
    HoverPoints *hoverPoints() const { return m_hoverPoints; }

public slots:
    void setGradientStops(const QGradientStops &stops);

    void setPadSpread();
    void setRepeatSpread();
    void setReflectSpread();

    void setLinearGradient();
    void setRadialGradient();
    void setConicalGradient();

protected:
    void paint(QPainter *painter) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    QGradientStops m_stops;
    HoverPoints *m_hoverPoints;
    QGradient::Spread m_spread;
    Qt::BrushStyle m_gradientType;
};

#endif // GRADIENTRENDERER_H
