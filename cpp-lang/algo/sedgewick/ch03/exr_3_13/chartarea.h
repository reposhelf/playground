#ifndef CHARTAREA_H
#define CHARTAREA_H

#include <QWidget>

struct Coordinate
{
    Coordinate(int x = 0, int y = 0) : X(x), Y(y) {}
    int X;
    int Y;
};

class ChartArea : public QWidget
{
    Q_OBJECT

public:
    explicit ChartArea(QWidget *parent = 0);
    ~ChartArea();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void setCoordinates(const QVector<Coordinate> &coordinates);

protected:
    void paintEvent(QPaintEvent *event);

private:
    void drawCoordinate(QPainter &painter) const;
    int xAxisWidth() const;
    int yAxisWidth() const;

    QRect m_nBoundingRect;
    QRect m_primesBoundingRect;
    QVector<Coordinate> m_coordinates;
};

#endif // CHARTAREA_H
