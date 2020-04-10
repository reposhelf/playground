#include "chartarea.h"
#include "eratosthenessieve.h"
#include "josephushelection.h"

#include <QApplication>

int do_exr_3_13(const QApplication &app);
int do_exr_3_30(const QApplication &app);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    return do_exr_3_30(app);
}

int do_exr_3_13(const QApplication &app)
{
    QVector<Coordinate> coorditnates;
    for (uint x = 50; x <= 1000; x += 50) {
        uint y = EratosthenesSieve::primeCount(x);
        coorditnates.append(Coordinate(x, y));
    }
    ChartArea chart(QStringLiteral("N"), QStringLiteral("PRIMES"));
    chart.setCoordinates(coorditnates);
    chart.show();
    return app.exec();
}

int do_exr_3_30(const QApplication &app)
{
    QVector<Coordinate> coorditnates;
    const int m = 10;
    for (uint x = 2; x <= 100; ++x) {
        uint y = JosephushElection::value(m, x);
        coorditnates.append(Coordinate(x, y));
    }
    ChartArea chart(QStringLiteral("N"), QStringLiteral("COUNTS"));
    chart.setCoordinates(coorditnates);
    chart.show();
    return app.exec();
}
