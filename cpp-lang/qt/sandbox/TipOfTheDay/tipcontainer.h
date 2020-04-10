#ifndef TIPCONTAINER_H
#define TIPCONTAINER_H

#include <QVector>
#include "tip.h"

class TipContainer
{
public:
    TipContainer();
    ~TipContainer();

    Tip tip   (int index) const;
    int count () const;

private:
    void initialize();

    QVector<Tip *> m_tips;
};

#endif // TIPCONTAINER_H
