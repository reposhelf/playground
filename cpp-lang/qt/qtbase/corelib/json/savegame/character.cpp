#include "character.h"

#include <QJsonObject>

Character::Character()
    : m_name(),
      m_level(0),
      m_classType(Warrior)
{
}

Character::Character(const QString &name, int level, Character::ClassType classType)
    : m_name(name),
      m_level(level),
      m_classType(classType)
{
}

QString Character::name() const
{
    return m_name;
}

void Character::setName(const QString &name)
{
    m_name = name;
}

int Character::level() const
{
    return m_level;
}

void Character::setLevel(int level)
{
    m_level = level;
}

Character::ClassType Character::classType() const
{
    return m_classType;
}

void Character::setClassType(Character::ClassType classType)
{
    m_classType = classType;
}

void Character::read(const QJsonObject &json)
{
    m_name = json["name"].toString();
    m_level = json["level"].toDouble();
    m_classType = ClassType(qRound(json["classType"].toDouble()));
}

void Character::write(QJsonObject &json) const
{
    json["name"] = m_name;
    json["level"] = m_level;
    json["classType"] = m_classType;
}
