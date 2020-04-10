#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QQmlListProperty>
#include <QPair>

#include "philosopheritem.h"
#include "table.h"

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<PhilosopherItem> philosophers READ philosophers
               NOTIFY philosophersChanged)
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    Q_INVOKABLE void addPhilosopher(const QString &name);
    Q_INVOKABLE void removePhilosopher(int id);

    QQmlListProperty<PhilosopherItem> philosophers();

signals:
    void philosophersChanged(QQmlListProperty<PhilosopherItem>);

private:
    void init();
    void setupGrid();
    void placePhilosopherItem(PhilosopherItem *philosopherItem);

    QList<PhilosopherItem *> philosopherItems_;
    Table *table_;

    // Holds available coordinates (x, y) for PhilosopherItem object
    struct Cell
    {
        int X = 0;
        int Y = 0;
        bool FREE = true;
        Cell(int x, int y, bool free)
            : X(x), Y(y), FREE(free) {}
    };
    QList<Cell> grid_;
};

#endif // CONTROLLER_H
