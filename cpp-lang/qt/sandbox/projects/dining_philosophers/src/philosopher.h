#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <QThread>

#include "table.h"

class Philosopher : public QThread
{
    Q_OBJECT
public:
    Philosopher(const QString &name = QString(), QObject *parent = nullptr);
    Philosopher(Table *table, const QString &name = QString(), QObject *parent = nullptr);
    ~Philosopher();

    enum State { Eating, Thinking };

    QString name() const { return name_; }
    void setName(const QString &name);

    State state() const { return state_; }
    void setState(State state);

    Table *table() const { return table_; }
    void setTable(Table *table);

signals:
    void nameChanged(const QString&);
    void stateChanged(Philosopher::State);
    void tableChanged(Table*);

protected:
    void run() override;

private slots:
    void stop();
    void eat();

private:
    QString name_;
    State state_ = Thinking;
    Table *table_ = nullptr;
    QPair<int, int> *forksIndicesPair_ = nullptr;
    bool stop_ = false;
};

#endif // PHILOSOPHER_H
