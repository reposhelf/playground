#include "chartarea.h"

#include <QPainter>

const int Offset = 15;

ChartArea::ChartArea(QWidget *parent)
    : QWidget(parent),
      m_nBoundingRect(),
      m_primesBoundingRect(),
      m_coordinates()
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    QFont newFont = font();
    newFont.setPointSize(11);
    setFont(newFont);

    QFontMetrics fm(font());
    m_nBoundingRect = fm.boundingRect("N");
    m_primesBoundingRect = fm.boundingRect("PRIMES");
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

void ChartArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(Offset, height() - Offset);

    drawCoordinate(painter);
}

void ChartArea::drawCoordinate(QPainter &painter) const
{
    // draw x axis
    painter.drawLine(0, 0, xAxisWidth(), 0);
    // draw arrow for x axis
    painter.drawLine(xAxisWidth(), 0, xAxisWidth() - 5, -2);
    painter.drawLine(xAxisWidth(), 0, xAxisWidth() - 5, 2);
    // draw text for x axis
    painter.drawText(xAxisWidth() + 5, 0 + m_nBoundingRect.height() / 3, tr("N"));

    // darw y axis
    painter.drawLine(0, 0, 0, yAxisWidth());
    // darw arrow for y axis
    painter.drawLine(0, yAxisWidth(), -2, yAxisWidth() + 5);
    painter.drawLine(0, yAxisWidth(), 2, yAxisWidth() + 5);
    // draw text for y axis
    painter.drawText(0 - Offset, yAxisWidth() - m_primesBoundingRect.height(), tr("PRIMES"));

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
    return width() - 2 * Offset - m_nBoundingRect.width();
}

int ChartArea::yAxisWidth() const
{
    return -(height() - Offset * 2 - m_primesBoundingRect.height());
}
