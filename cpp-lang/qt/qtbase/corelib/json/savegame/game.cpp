#include "game.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>

Game::Game()
    : m_player(),
      m_levels()
{
}

const Character &Game::player() const
{
    return m_player;
}

const QList<Level> &Game::levels() const
{
    return m_levels;
}

void Game::newGame()
{
    m_player.setName(QStringLiteral("Hero"));
    m_player.setClassType(Character::Archer);
    m_player.setLevel(15);

    m_levels.clear();

    Level village;
    QList<Character> villageNpcs;
    villageNpcs << Character(QStringLiteral("Barry the Blacksmith"), 10, Character::Warrior);
    villageNpcs << Character(QStringLiteral("Terry the Trader"), 10, Character::Warrior);
    village.setNpcs(villageNpcs);
    m_levels << village;

    Level dungeon;
    QList<Character> dungeonNpcs;
    dungeonNpcs << Character(QStringLiteral("Eric the Evil"), 20, Character::Mage);
    dungeonNpcs << Character(QStringLiteral("Eric's Sidekick #1"), 5, Character::Warrior);
    dungeonNpcs << Character(QStringLiteral("Eric's Sidecick #2"), 5, Character::Warrior);
    dungeon.setNpcs(dungeonNpcs);
    m_levels << dungeon;
}

bool Game::loadGame(Game::SaveFormat saveFormat)
{
    QFile loadFile(saveFormat == Json
                   ? QStringLiteral("save.json")
                   : QStringLiteral("save.dat"));

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file");
        return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(saveFormat == Json
                          ? QJsonDocument::fromJson(saveData)
                          : QJsonDocument::fromBinaryData(saveData));

    read(loadDoc.object());

    return true;
}

bool Game::saveGame(Game::SaveFormat saveFormat) const
{
    QFile saveFile(saveFormat == Json
                   ? QStringLiteral("save.json")
                   : QStringLiteral("save.dat"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file");
        return false;
    }

    QJsonObject gameObject;
    write(gameObject);
    QJsonDocument saveDoc(gameObject);
    saveFile.write(saveFormat == Json
                   ? saveDoc.toJson()
                   : saveDoc.toBinaryData());

    return true;
}

void Game::read(const QJsonObject &json)
{
    m_player.read(json["player"].toObject());

    m_levels.clear();
    QJsonArray levelArray = json["levels"].toArray();
    for (int levelIndex = 0; levelIndex < levelArray.size(); ++levelIndex) {
        QJsonObject levelObject = levelArray[levelIndex].toObject();
        Level level;
        level.read(levelObject);
        m_levels << level;
    }
}

void Game::write(QJsonObject &json) const
{
    QJsonObject playerObject;
    m_player.write(playerObject);
    json["player"] = playerObject;

    QJsonArray levelArray;
    foreach (const Level level, m_levels) {
        QJsonObject levelObject;
        level.write(levelObject);
        levelArray.append(levelObject);
    }
    json["levels"] = levelArray;
}
