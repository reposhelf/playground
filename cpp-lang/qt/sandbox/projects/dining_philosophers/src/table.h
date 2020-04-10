#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QList>
#include <QPair>
#include <QMutex>
#include <QWaitCondition>

#include <mutex>

struct Sync
{
    QWaitCondition accessIsOpen;
    QMutex mutex;
};

class Table : public QObject
{
    Q_OBJECT
public:
    static Sync &sync();

    explicit Table(int forksCount, QObject *parent = nullptr);
    ~Table();

    bool accessible() const { return accessible_; }
    void setAccessible(bool accessible);

    std::mutex *fork(int index) const;
    void addFork();
    void removeFork();

    QPair<int, int> *makeForksIndicesPair();
    void removeForksIndicesPair(QPair<int, int> *forksIndicesPair);

    int forksCount() const { return forks_.count(); }

signals:
    void accessibleChanged(bool);

private:
    void updateForksIndicesPairs();

    QList<std::mutex *> forks_;
    // Holds pairs of forks indices for each philosopher.
    // For example:
    //  - philosopher_1 has forks by indices [0, 1];
    //  - philosopher_2 has forks by indices [1, 2];
    //  - philosopher_3 has forks by indices [2, 3];
    //  - philosopher_N has forks by indices [0, forks_count - 1];
    // Note that the last pair must have order as described to prevent deadlock.
    QList<QPair<int, int> *> forksIndicesPairs_;
    bool accessible_ = true;
};

#endif // TABLE_H
