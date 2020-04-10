#ifndef SHADEWIDGET_H
#define SHADEWIDGET_H

#include <QWidget>

class HoverPoints;
class ShadeWidget : public QWidget
{
    Q_OBJECT

public:
    enum ShadeType {
        RedShade,
        GreenShade,
        BlueShade,
        ARGBShade
    };

    ShadeWidget(ShadeType type, QWidget *parent = Q_NULLPTR);

    QSize sizeHint() const Q_DECL_OVERRIDE { return QSize(150, 40); }
    HoverPoints *hoverPoints() const { return m_hoverPoints; }
    QPolygonF points() const;
    uint colorAt(int x);

    void setGradientStops(const QGradientStops &stops);

signals:
    void colorsChanged();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    void generateShade();

    ShadeType m_shadeType;
    HoverPoints *m_hoverPoints;
    QImage m_shade;
    QLinearGradient m_alphaGradient;
};

#endif // SHADEWIDGET_H
