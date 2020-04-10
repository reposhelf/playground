#ifndef PATHSTROKERENDERER_H
#define PATHSTROKERENDERER_H

#include "arthurwidgets.h"

#include <QBasicTimer>

class PathStrokeRenderer : public ArthurFrame
{
    Q_OBJECT
    Q_PROPERTY(bool animated READ animated WRITE setAnimated)
    Q_PROPERTY(qreal penWidth READ realPenWidth WRITE setRealPenWidth)

public:
    enum PathMode {
        CurveMode,
        LineMode
    };

    PathStrokeRenderer(bool smallScreen = false, QWidget *parent = Q_NULLPTR);

    QSize sizeHint() const Q_DECL_OVERRIDE { return QSize(500, 500); }

    bool animated() const { return m_timer.isActive(); }

    qreal realPenWidth() const { return m_penWidth; }
    void setRealPenWidth(qreal penWidth);

signals:
    void clicked();

protected:
    void paint(QPainter *painter) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    bool event(QEvent *event) Q_DECL_OVERRIDE;

public slots:
    void setPenWidth(int penWidth);
    void setAnimated(bool animated);

    void setFlatCap();
    void setSquareCap();
    void setRoundCap();

    void setBevelJoin();
    void setMiterJoin();
    void setRoundJoin();

    void setCurveMode();
    void setLineMode();

    void setSolidLine();
    void setDashLine();
    void setDotLine();
    void setDashDotLine();
    void setDashDotDotLine();
    void setCustomDashLine();

private:
    void initializePoints();
    void updatePoints();

    bool m_wasAnimated;
    qreal m_penWidth;

    PathMode m_pathMode;

    Qt::PenJoinStyle m_joinStyle;
    Qt::PenCapStyle m_capStyle;
    Qt::PenStyle m_penStyle;

    bool m_smallScreen;
    QPoint m_mousePress;
    bool m_mouseDrag;

    int m_pointCount;
    int m_pointSize;
    int m_activePoint;
    QVector<QPointF> m_points;
    QVector<QPointF> m_vectors;
    QHash<int, int> m_fingerPointMapping;

    QBasicTimer m_timer;
};

#endif // PATHSTROKERENDERER_H
