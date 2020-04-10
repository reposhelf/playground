#include "level.h"

#include <QJsonObject>
#include <QJsonArray>

Level::Level()
    : m_npcs()
{
}

const QList<Character> &Level::npcs() const
{
    return m_npcs;
}

void Level::setNpcs(const QList<Character> &npcs)
{
    m_npcs = npcs;
}

void Level::read(const QJsonObject &json)
{
    m_npcs.clear();
    QJsonArray npcArray = json["npcs"].toArray();
    for (int npcIndex = 0; npcIndex < npcArray.size(); ++npcIndex) {
        QJsonObject npcObject = npcArray[npcIndex].toObject();
        Character npc;
        npc.read(npcObject);
        m_npcs.append(npc);
    }
}

void Level::write(QJsonObject &json) const
{
    QJsonArray npcArray;
    foreach (const Character npc, m_npcs) {
        QJsonObject npcObject;
        npc.write(npcObject);
        npcArray.append(npcObject);
    }
    json["npcs"] = npcArray;
}
