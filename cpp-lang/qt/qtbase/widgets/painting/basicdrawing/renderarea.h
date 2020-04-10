#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPixmap>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    enum Shape {
        Line,
        Points,
        PolyLine,
        Polygon,
        Rect,
        RoundedRect,
        Ellipse,
        Arc,
        Chord,
        Pie,
        Path,
        Text,
        Pixmap
    };

    RenderArea(QWidget *parent = Q_NULLPTR);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialised(bool antialised);
    void setTransformed(bool transformed);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    Shape m_shape;
    QPen m_pen;
    QBrush m_brush;
    bool m_antialised;
    bool m_transformed;
    QPixmap m_pixmap;
};

#endif // RENDERAREA_H
