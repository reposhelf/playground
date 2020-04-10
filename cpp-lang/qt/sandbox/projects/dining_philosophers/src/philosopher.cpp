#include "philosopher.h"

Philosopher::Philosopher(const QString &name, QObject *parent)
    : QThread(parent),
      name_(name)
{
}

Philosopher::Philosopher(Table *table, const QString &name, QObject *parent)
    : QThread(parent),
      name_(name),
      table_(table)
{
    if (table_ != nullptr)
        forksIndicesPair_ = table_->makeForksIndicesPair();
}

Philosopher::~Philosopher()
{
    if (table_ != nullptr)
        table_->removeForksIndicesPair(forksIndicesPair_);
}

void Philosopher::setName(const QString &name)
{
    if (name_ == name)
        return;

    name_ = name;
    emit nameChanged(name_);
}

void Philosopher::setState(State state)
{
    if (state_ == state)
        return;

    state_ = state;
    emit stateChanged(state_);
}

void Philosopher::setTable(Table *table)
{
    if (table_ == table)
        return;

    if (table_ == nullptr || table == nullptr)
        return;

    table_->removeForksIndicesPair(forksIndicesPair_);

    table_ = table;

    forksIndicesPair_ = table_->makeForksIndicesPair();

    emit tableChanged(table_);
}

void Philosopher::run()
{
    while (true)
    {
        eat();
        msleep(1000);

        if (stop_)
            break;
    }
}

void Philosopher::stop()
{
    stop_ = true;
}

void Philosopher::eat()
{
    if (table_ == nullptr)
        return;

    Table::sync().mutex.lock();
    if (!table_->accessible())
        Table::sync().accessIsOpen.wait(&Table::sync().mutex);
    Table::sync().mutex.unlock();

    std::mutex &mLeft = *(table_->fork(forksIndicesPair_->first));
    std::mutex &mRight = *(table_->fork(forksIndicesPair_->second));
    std::mutex mTemp;

    std::lock(mLeft, mRight, mTemp);
    std::lock_guard<std::mutex> left(mLeft, std::adopt_lock);
    std::lock_guard<std::mutex> right(mRight, std::adopt_lock);

    setState(Eating);

    msleep(1000);

    setState(Thinking);
}
