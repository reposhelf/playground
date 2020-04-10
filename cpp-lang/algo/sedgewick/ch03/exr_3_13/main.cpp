#include "chartarea.h"
#include "eratosthenessieve.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QVector<Coordinate> coorditnates;

    for (int i = 50; i <= 1000; i += 50) {
        uint x = i;
        uint y = EratosthenesSieve::primeCount(i);

        coorditnates.append(Coordinate(x, y));
    }
    ChartArea eratosthenesSieveChart;
    eratosthenesSieveChart.setCoordinates(coorditnates);
    eratosthenesSieveChart.show();

    return app.exec();
}
