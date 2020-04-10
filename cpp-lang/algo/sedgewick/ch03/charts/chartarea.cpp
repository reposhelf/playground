#include "chartarea.h"

#include <QPainter>

const int OFFSET = 30;

ChartArea::ChartArea(QWidget *parent)
    : QWidget(parent),
      m_xAxisTitle(QStringLiteral("X")),
      m_yAxisTitle(QStringLiteral("Y")),
      m_xBoundingRect(),
      m_yBoundingRect(),
      m_coordinates()
{
    initialize();
}

ChartArea::ChartArea(const QString &xAxisTitle, const QString &yAxisTitle, QWidget *parent)
    : QWidget(parent),
      m_xAxisTitle(xAxisTitle),
      m_yAxisTitle(yAxisTitle),
      m_xBoundingRect(),
      m_yBoundingRect(),
      m_coordinates()
{
    initialize();
}

ChartArea::~ChartArea()
{
}

QSize ChartArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize ChartArea::sizeHint() const
{
    return QSize(800, 500);
}

void ChartArea::setCoordinates(const QVector<Coordinate> &coordinates)
{
    m_coordinates = coordinates;
    update();
}

void ChartArea::setXAxisTitle(const QString &title)
{
    m_xAxisTitle = title;
    update();
}

void ChartArea::setYAxisTitle(const QString &title)
{
    m_yAxisTitle = title;
    update();
}

void ChartArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(OFFSET, height() - OFFSET);

    drawCoordinate(painter);
}

void ChartArea::initialize()
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    QFont newFont = font();
    newFont.setPointSize(11);
    setFont(newFont);

    QFontMetrics fm(font());
    m_xBoundingRect = fm.boundingRect(m_xAxisTitle);
    m_yBoundingRect = fm.boundingRect(m_yAxisTitle);
}

void ChartArea::drawCoordinate(QPainter &painter) const
{
    // draw x axis
    painter.drawLine(0, 0, xAxisWidth(), 0);
    // draw arrow for x axis
    painter.drawLine(xAxisWidth(), 0, xAxisWidth() - 5, -2);
    painter.drawLine(xAxisWidth(), 0, xAxisWidth() - 5, 2);
    // draw text for x axis
    painter.drawText(xAxisWidth() + 5, 0 + m_xBoundingRect.height() / 3, m_xAxisTitle);

    // darw y axis
    painter.drawLine(0, 0, 0, yAxisWidth());
    // darw arrow for y axis
    painter.drawLine(0, yAxisWidth(), -2, yAxisWidth() + 5);
    painter.drawLine(0, yAxisWidth(), 2, yAxisWidth() + 5);
    // draw text for y axis
    painter.drawText(0 - m_yBoundingRect.width() / 2, yAxisWidth() - m_yBoundingRect.height(), m_yAxisTitle);

    // draw coordinates
    painter.setPen(Qt::red);
    int step = xAxisWidth() / m_coordinates.count();
    QPoint points[m_coordinates.count()];
    int pointId = 0;

    for (int i = step; i <= xAxisWidth(); i += step) {
        if (pointId < m_coordinates.count())
            points[pointId] = QPoint(i, m_coordinates[pointId].Y * (yAxisWidth() / m_coordinates.last().Y));
        ++pointId;
    }
    painter.drawPolyline(points, m_coordinates.count());
}

int ChartArea::xAxisWidth() const
{
    return width() - 2 * OFFSET - m_xBoundingRect.width();
}

int ChartArea::yAxisWidth() const
{
    return -(height() - OFFSET * 2 - m_yBoundingRect.height());
}
