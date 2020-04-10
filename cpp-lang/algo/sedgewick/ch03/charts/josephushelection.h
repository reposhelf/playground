#ifndef JOSEPHUSHELECTION_H
#define JOSEPHUSHELECTION_H

#include <QObject>

class JosephushElection
{
    Q_DISABLE_COPY(JosephushElection)

public:
    static uint value(uint m, uint n);
};

#endif // JOSEPHUSHELECTION_H
