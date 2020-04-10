#include "result.h"

Result::Result(QObject *parent)
    : QObject(parent)
{
}

void Result::setFirstPlayerName(const QString &name)
{
    if (m_players[FirstPlayer].NAME == name)
        return;
    m_players[FirstPlayer].NAME = name;
    emit firstPlayerNameChanged(name);
}

void Result::setSecondPlayerName(const QString &name)
{
    if (m_players[SecondPlayer].NAME == name)
        return;
    m_players[SecondPlayer].NAME = name;
    emit secondPlayerNameChanged(name);
}

void Result::setFirstPlayerScore(qreal score)
{
    if (m_players[FirstPlayer].SCORE == score)
        return;
    m_players[FirstPlayer].SCORE = score;
    emit firstPlayerScoreChanged(score);
}

void Result::setSecondPlayerScore(qreal score)
{
    if (m_players[SecondPlayer].SCORE == score)
        return;
    m_players[SecondPlayer].SCORE = score;
    emit secondPlayerScoreChanged(score);
}
