#ifndef ERATOSTHENESSIEVE_H
#define ERATOSTHENESSIEVE_H

#include <QObject>

class EratosthenesSieve
{
    Q_DISABLE_COPY(EratosthenesSieve)

public:
    static uint primeCount(uint n);
};

#endif // ERATOSTHENESSIEVE_H
