#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

enum Operation { NoTransformation, Translate, Rotate, Scale };

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget *parent = 0);
    ~RenderArea();

    void setOperations(const QList<Operation> &operations);
    void setShape(const QPainterPath &shape);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    void drawCoordinates(QPainter &painter);
    void drawOutline(QPainter &painter);
    void drawShape(QPainter &painter);
    void transformPainter(QPainter &painter);

    QList<Operation> m_operations;
    QPainterPath m_shape;
    QRect m_xBoundingRect;
    QRect m_yBoundingRect;
};

#endif // RENDERAREA_H
