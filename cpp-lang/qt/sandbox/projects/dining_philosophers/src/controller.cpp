#include "controller.h"

namespace {
const QVector<QString> Names = {
    "Aristotle",
    "Kant",
    "Spinoza",
    "Marx",
    "Russel"};

const int DefaultWidth = 100;
const int DefaultHeight = 150;
const int DefaultMargin = 10;
const int XOffset = 150;
const int YOffset = 200;
const int RowSize = 5;
const int MaxPhilosophersCount = 20;
}

Controller::Controller(QObject *parent)
    : QObject(parent),
      table_(new Table(Names.count()))
{
    setupGrid();

    init();
}

Controller::~Controller()
{
    qDeleteAll(philosopherItems_);

    delete table_;
}

void Controller::addPhilosopher(const QString &name)
{
    if (philosopherItems_.count() == MaxPhilosophersCount)
        return;

    auto philosopherItem = new PhilosopherItem(name, table_, this);

    philosopherItem->setWidth(DefaultWidth);
    philosopherItem->setHeight(DefaultHeight);
    philosopherItems_.append(philosopherItem);

    placePhilosopherItem(philosopherItem);

    if (table_->forksCount() < philosopherItems_.count())
        table_->addFork();

    philosopherItem->startPhilosopher();
    emit philosophersChanged(philosophers());
}

void Controller::removePhilosopher(int id)
{
    auto iter = philosopherItems_.begin();
    auto end = philosopherItems_.end();
    for (; iter != end; ++iter)
    {
        if ((*iter)->id() == id)
            break;
    }

    if (iter != end)
    {
        auto philosopherItem = *iter;
        philosopherItems_.removeOne(philosopherItem);
        emit philosophersChanged(philosophers());

        for (auto it = grid_.begin(); it != grid_.end(); ++it)
        {
            if ((*it).X == philosopherItem->x() && (*it).Y == philosopherItem->y())
            {
                (*it).FREE = true;
                break;
            }
        }

        philosopherItem->deleteLater();
    }
}

QQmlListProperty<PhilosopherItem> Controller::philosophers()
{
    return QQmlListProperty<PhilosopherItem>(this, philosopherItems_);
}

void Controller::init()
{
    for (const auto &name : Names)
    {
        auto philosopherItem = new PhilosopherItem(name, table_, this);
        placePhilosopherItem(philosopherItem);
        philosopherItem->setWidth(DefaultWidth);
        philosopherItem->setHeight(DefaultHeight);
        philosopherItems_.append(philosopherItem);
        philosopherItem->startPhilosopher();
    }
}

void Controller::setupGrid()
{
    int x = DefaultMargin;
    int y = DefaultMargin;

    for (int i = 0; i != MaxPhilosophersCount; ++i)
    {
        grid_.append(Cell{x, y, true});

        if (i > 0 && ((i + 1) % RowSize) == 0)
        {
            x = DefaultMargin;
            y += YOffset;
        }
        else
        {
            x += XOffset;
        }
    }
}

void Controller::placePhilosopherItem(PhilosopherItem *philosopherItem)
{
    for (auto it = grid_.begin(); it != grid_.end(); ++it)
    {
        if ((*it).FREE == true)
        {
            philosopherItem->setX((*it).X);
            philosopherItem->setY((*it).Y);
            (*it).FREE = false;
            return;
        }
    }
}
