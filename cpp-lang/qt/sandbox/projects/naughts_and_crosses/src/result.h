#ifndef RESULT_H
#define RESULT_H

#include <QObject>

struct Player
{
    QString NAME;
    qreal SCORE = 0.0;
};

class Result : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString firstPlayerName READ firstPlayerName WRITE setFirstPlayerName
               NOTIFY firstPlayerNameChanged)
    Q_PROPERTY(QString secondPlayerName READ secondPlayerName WRITE setSecondPlayerName
               NOTIFY secondPlayerNameChanged)
    Q_PROPERTY(qreal firstPlayerScore READ firstPlayerScore WRITE setFirstPlayerScore
               NOTIFY firstPlayerScoreChanged)
    Q_PROPERTY(qreal secondPlayerScore READ secondPlayerScore WRITE setSecondPlayerScore
               NOTIFY secondPlayerScoreChanged)
public:
    explicit Result(QObject *parent = nullptr);

    enum { FirstPlayer = 0, SecondPlayer = 1, PlayersCount = 2 };

    QString firstPlayerName() const { return m_players[FirstPlayer].NAME; }
    QString secondPlayerName() const { return m_players[SecondPlayer].NAME; }
    qreal firstPlayerScore() const { return m_players[FirstPlayer].SCORE; }
    qreal secondPlayerScore() const { return m_players[SecondPlayer].SCORE; }

    void setFirstPlayerName(const QString&);
    void setSecondPlayerName(const QString&);
    void setFirstPlayerScore(qreal);
    void setSecondPlayerScore(qreal);

signals:
    void firstPlayerNameChanged(const QString&);
    void secondPlayerNameChanged(const QString&);
    void firstPlayerScoreChanged(qreal);
    void secondPlayerScoreChanged(qreal);
    void roundFinished(const QString &lastRoundText);

private:
    Player m_players[PlayersCount];
};

#endif // RESULT_H
