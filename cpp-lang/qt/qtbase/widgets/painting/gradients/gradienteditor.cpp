#include "gradienteditor.h"
#include "shadewidget.h"
#include "hoverpoints.h"

#include <QtWidgets>

#include <QDebug>

inline static bool xLessThan(const QPointF &p1, const QPointF &p2)
{
    return p1.x() < p2.x();
}

static void setShadePoints(const QPolygonF &points, ShadeWidget *shade)
{
    shade->hoverPoints()->setPoints(points);
    shade->hoverPoints()->setPointLock(0, HoverPoints::LockToLeft);
    shade->hoverPoints()->setPointLock(points.size() - 1, HoverPoints::LockToRight);
    shade->update();
}

GradientEditor::GradientEditor(QWidget *parent)
    : QWidget(parent),
      m_redShade(new ShadeWidget(ShadeWidget::RedShade, this)),
      m_greenShade(new ShadeWidget(ShadeWidget::GreenShade, this)),
      m_blueShade(new ShadeWidget(ShadeWidget::BlueShade, this)),
      m_alphaShade(new ShadeWidget(ShadeWidget::ARGBShade, this))
{
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setSpacing(1);
    vbox->setMargin(1);

    vbox->addWidget(m_redShade);
    vbox->addWidget(m_greenShade);
    vbox->addWidget(m_blueShade);
    vbox->addWidget(m_alphaShade);

    connect(m_redShade, &ShadeWidget::colorsChanged, this, &GradientEditor::updatePoints);
    connect(m_greenShade, &ShadeWidget::colorsChanged, this, &GradientEditor::updatePoints);
    connect(m_blueShade, &ShadeWidget::colorsChanged, this, &GradientEditor::updatePoints);
    connect(m_alphaShade, &ShadeWidget::colorsChanged, this, &GradientEditor::updatePoints);
}

void GradientEditor::setGradientStops(const QGradientStops &stops)
{
    QPolygonF redPoints;
    QPolygonF greenPoints;
    QPolygonF bluePoints;
    QPolygonF alphaPoints;

    qreal redHeight = m_redShade->height();
    qreal greenHeight = m_greenShade->height();
    qreal blueHeight = m_blueShade->height();
    qreal alphaHeight = m_alphaShade->height();

    for (int i = 0; i < stops.size(); ++i) {
        qreal pos = stops.at(i).first;
        QRgb color = stops.at(i).second.rgba();

        redPoints << QPointF(pos * m_redShade->width(), redHeight - qRed(color) * redHeight / 255);
        greenPoints << QPointF(pos * m_greenShade->width(), greenHeight - qGreen(color) * greenHeight / 255);
        bluePoints << QPointF(pos * m_blueShade->width(), blueHeight - qBlue(color) * blueHeight / 255);
        alphaPoints << QPointF(pos * m_alphaShade->width(), alphaHeight - qAlpha(color) * alphaHeight / 255);
    }

    setShadePoints(redPoints, m_redShade);
    setShadePoints(greenPoints, m_greenShade);
    setShadePoints(bluePoints, m_blueShade);
    setShadePoints(alphaPoints, m_alphaShade);
}

void GradientEditor::updatePoints()
{
    QPolygonF points;
    points += m_redShade->points();
    points += m_greenShade->points();
    points += m_blueShade->points();
    points += m_alphaShade->points();
    std::sort(points.begin(), points.end(), xLessThan);

    qreal shadeWidth = m_alphaShade->width();
    QGradientStops stops;

    for (int i = 0; i < points.size(); ++i) {
        qreal x = points.at(i).x();
        if (i + i < points.size() && x == points.at(i + 1).x())
            continue;
        QColor color((0x00ff0000 & m_redShade->colorAt(int(x))) >> 16,
                     (0x0000ff00 & m_greenShade->colorAt(int(x))) >> 8,
                     (0x000000ff & m_blueShade->colorAt(int(x))),
                     (0xff000000 & m_alphaShade->colorAt(int(x))) >> 24);
        if (x / shadeWidth > 1)
            return;

        stops << QGradientStop(x / shadeWidth, color);
    }

    m_alphaShade->setGradientStops(stops);

    emit gradientStopsChanged(stops);
}
