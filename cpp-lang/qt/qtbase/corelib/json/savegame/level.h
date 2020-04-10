#ifndef LEVEL_H
#define LEVEL_H

#include "character.h"

#include <QList>

class Level
{
public:
    Level();

    const QList<Character> &npcs() const;
    void setNpcs(const QList<Character> &npcs);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    QList<Character> m_npcs;
};

#endif // LEVEL_H
