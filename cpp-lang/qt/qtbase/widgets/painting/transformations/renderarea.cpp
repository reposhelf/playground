#include "renderarea.h"

#include <QtWidgets>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent),
      m_operations(),
      m_shape(),
      m_xBoundingRect(),
      m_yBoundingRect()
{
    QFont newFont = font();
    newFont.setPixelSize(12); // device dependent font size
    setFont(newFont);

    QFontMetrics fm(font());
    m_xBoundingRect = fm.boundingRect(tr("x"));
    m_yBoundingRect = fm.boundingRect(tr("y"));
}

RenderArea::~RenderArea()
{
}

void RenderArea::setOperations(const QList<Operation> &operations)
{
    m_operations = operations;
    update();
}

void RenderArea::setShape(const QPainterPath &shape)
{
    m_shape = shape;
    update();
}

QSize RenderArea::minimumSizeHint() const
{
    // The default implementation of this function
    // returns an invalid size if there is no layout
    // for this widget, and returns the layout's
    // minimum size, otherwise.
    return QSize(182, 182);
}

QSize RenderArea::sizeHint() const
{
    // The default implementation of this function
    // returns an invalid size if there is no layout
    // for this widget, and returns the layout's
    // preffered size, otherwise.
    return QSize(232, 232);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), QBrush(Qt::white));

    painter.translate(66, 66);

    painter.save();
    transformPainter(painter);
    drawShape(painter);
    painter.restore();

    drawOutline(painter);

    transformPainter(painter);
    drawCoordinates(painter);
}

void RenderArea::drawCoordinates(QPainter &painter)
{
    painter.setPen(Qt::red);

    painter.drawLine(0, 0, 50, 0);
    painter.drawLine(48, -2, 50, 0);
    painter.drawLine(48, 2, 50, 0);
    painter.drawText(60 - m_xBoundingRect.width() / 2,
                     0 + m_yBoundingRect.height() / 2, tr("x"));

    painter.drawLine(0, 0, 0, 50);
    painter.drawLine(-2, 48, 0, 50);
    painter.drawLine(2, 48, 0, 50);
    painter.drawText(0 - m_yBoundingRect.width() / 2,
                     60 + m_yBoundingRect.height() / 2, tr("y"));
}

void RenderArea::drawOutline(QPainter &painter)
{
    painter.setPen(Qt::darkGreen);
    painter.setPen(Qt::DashLine);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(0, 0, 100, 100);
}

void RenderArea::drawShape(QPainter &painter)
{
    painter.fillPath(m_shape, Qt::blue);
}

void RenderArea::transformPainter(QPainter &painter)
{
    for (Operation operation : m_operations) {
        switch (operation) {
        case Translate:
            painter.translate(50, 50);
            break;
        case Scale:
            painter.scale(0.75, 0.75);
            break;
        case Rotate:
            painter.rotate(60);
            break;
        case NoTransformation:
        default:
            break;
        }
    }
}
