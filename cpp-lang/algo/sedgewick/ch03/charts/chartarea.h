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
    ChartArea(QWidget *parent = Q_NULLPTR);
    ChartArea(const QString &xAxisTitle, const QString &yAxisTitle, QWidget *parent = Q_NULLPTR);
    ~ChartArea();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void setCoordinates(const QVector<Coordinate> &coordinates);
    void setXAxisTitle(const QString &title);
    void setYAxisTitle(const QString &title);

protected:
    void paintEvent(QPaintEvent *event);

private:
    void initialize();
    void drawCoordinate(QPainter &painter) const;
    int xAxisWidth() const;
    int yAxisWidth() const;

    QString m_xAxisTitle;
    QString m_yAxisTitle;
    QRect m_xBoundingRect;
    QRect m_yBoundingRect;
    QVector<Coordinate> m_coordinates;
};

#endif // CHARTAREA_H
