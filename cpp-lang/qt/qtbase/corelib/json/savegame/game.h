#ifndef GAME_H
#define GAME_H

#include "level.h"

#include <QList>

class Game
{
public:
    enum SaveFormat {
        Json, Binary
    };

    Game();

    const Character &player() const;
    const QList<Level> &levels() const;

    void newGame();
    bool loadGame(SaveFormat saveFormat);
    bool saveGame(SaveFormat saveFormat) const;

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    Character m_player;
    QList<Level> m_levels;
};

#endif // GAME_H
