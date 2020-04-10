#ifndef PATHDEFORM_H
#define PATHDEFORM_H

#include "arthurwidgets.h"

#include <QBasicTimer>
#include <QDateTime>

class PathDeformRenderer : public ArthurFrame
{
    Q_OBJECT
    Q_PROPERTY(bool animated READ animated WRITE setAnimated)
    Q_PROPERTY(int radius READ radius WRITE setRadius)
    Q_PROPERTY(int fontSize READ fontSize WRITE setFontSize)
    Q_PROPERTY(int intensity READ intensity WRITE setIntensity)
    Q_PROPERTY(QString text READ text WRITE setText)

public:
    PathDeformRenderer(QWidget *parent, bool smalScreen);

    QSize sizeHint() const Q_DECL_OVERRIDE { return QSize(600, 500); }
    bool animated() const { return m_animated; }
    int radius() const { return int(m_radius); }
    int fontSize() const { return m_fontSize; }
    int intensity() const { return int(m_intensity); }
    QString text() const { return m_text; }

signals:
    void clicked();

public slots:
    void setAnimated(bool animated);
    void setRadius(int radius);
    void setFontSize(int fontSize);
    void setIntensity(int intensity);
    void setText(const QString &text);

protected:
    void paint(QPainter *painter) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

private:
    void generateLensPixmap();
    QPainterPath lensDeform(const QPainterPath &source, const QPointF &offset);

    bool m_animated;
    qreal m_radius;
    int m_fontSize;
    qreal m_intensity;
    QString m_text;

    QBasicTimer m_repaintTimer;
    QTime m_repaintTracker;
    QVector<QPainterPath> m_paths;
    QVector<QPointF> m_advances;
    QRectF m_pathBounds;
    QPixmap m_lensPixmap;
    QImage m_lensImage;
    QPointF m_pos;  // center of the lens
    QPointF m_offset;
    QPointF m_direction;
    QPointF m_mousePress;
    bool m_mouseDrag;
    bool m_smallScreen;
};

class PathDeformControls : public QWidget
{
    Q_OBJECT

public:
    PathDeformControls(QWidget *parent, PathDeformRenderer *renderer, bool smallScreen);

signals:
    void okPressed();
    void quitPressed();

private:
    void layoutForDesktop();
    void layoutForSmallScreen();

    PathDeformRenderer *m_renderer;
};

class PathDeformWidget : public QWidget
{
    Q_OBJECT

public:
    PathDeformWidget(QWidget *parent, bool smallScreen);

    void setStyle(QStyle *style);

private slots:
    void showControls();
    void hideControls();

private:
    PathDeformRenderer *m_renderer;
    PathDeformControls *m_controls;
};
#endif // PATHDEFORM_H
