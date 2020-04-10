#include "table.h"

Sync &Table::sync()
{
    static Sync s;
    return s;
}

Table::Table(int forksCount, QObject *parent)
    : QObject(parent)
{
    for (; (forksCount--) != 0;)
        forks_.append(new std::mutex);
}

Table::~Table()
{
    qDeleteAll(forks_);
    qDeleteAll(forksIndicesPairs_);
}

void Table::setAccessible(bool accessible)
{
    if (accessible_ == accessible)
        return;

    accessible_ = accessible;
    emit accessibleChanged(accessible_);
}

std::mutex *Table::fork(int index) const
{
    Q_ASSERT(index >= 0 && index < forks_.count());

    return forks_.at(index);
}

void Table::addFork()
{
    forks_.append(new std::mutex);
}

void Table::removeFork()
{
    // TODO: add implementation
}

QPair<int, int> *Table::makeForksIndicesPair()
{
    forksIndicesPairs_.append(new QPair<int, int>);

    updateForksIndicesPairs();

    return forksIndicesPairs_.last();

}

void Table::removeForksIndicesPair(QPair<int, int> *forksIndicesPair)
{
    if (forksIndicesPair == nullptr)
        return;

    forksIndicesPairs_.removeOne(forksIndicesPair);

    delete forksIndicesPair;

    updateForksIndicesPairs();
}

void Table::updateForksIndicesPairs()
{
    setAccessible(false);
    sync().mutex.lock();

    for (int i = 0; i != forksIndicesPairs_.count(); ++i)
    {
        forksIndicesPairs_[i]->first = i;
        forksIndicesPairs_[i]->second = i + 1;
    }

    // to prevent deadlock last pair should have order
    // like [0, forks_count - 1]
    if (forksIndicesPairs_.count() > 1)
    {
        forksIndicesPairs_.last()->first = 0;
        forksIndicesPairs_.last()->second = forksIndicesPairs_.count() - 1;
    }

    setAccessible(true);
    sync().accessIsOpen.wakeAll();
    sync().mutex.unlock();
}
