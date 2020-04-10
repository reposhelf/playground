#include "philosopheritem.h"

namespace {
const QString ThinkingStateString = "Thinking";
const QString EatingStateString = "Eating";

int unique()
{
    static int unique = 0;
    return unique++;
}
}

PhilosopherItem::PhilosopherItem(const QString &name, Table *table, QObject *parent)
    : QObject(parent),
      philosopher_(new Philosopher(table, name))
{
    id_ = unique();

    setPhilosopherStateString(ThinkingStateString);

    connect(this, SIGNAL(stopPhilosopherRequest()), philosopher_, SLOT(stop()));
    connect(philosopher_, SIGNAL(stateChanged(Philosopher::State)),
            this, SLOT(onPhilosopherStateChanged(Philosopher::State)));
}

PhilosopherItem::~PhilosopherItem()
{
    emit stopPhilosopherRequest();

    philosopher_->quit();
    philosopher_->wait();
    philosopher_->deleteLater();
}

QString PhilosopherItem::philosopherName() const
{
    return philosopher_->name();
}

void PhilosopherItem::setPhilosopherName(const QString &name)
{
    if (philosopherName() == name)
        return;

    philosopher_->setName(name);
    emit philosopherNameChanged(name);
}

void PhilosopherItem::setX(int x)
{
    if (x_ == x)
        return;

    x_ = x;
    emit xChanged(x_);
}

void PhilosopherItem::setY(int y)
{
    if (y_ == y)
        return;

    y_ = y;
    emit xChanged(y_);
}

void PhilosopherItem::setWidth(int width)
{
    if (width_ == width)
        return;

    width_ = width;
    emit widthChanged(width_);
}

void PhilosopherItem::setHeight(int height)
{
    if (height_ == height)
        return;

    height_ = height;
    emit heightChanged(height_);
}

void PhilosopherItem::setPhilosopherStateString(const QString &stateStr)
{
    if (philosopherStateString_ == stateStr)
        return;

    philosopherStateString_ = stateStr;
    emit philosopherStateStringChanged(philosopherStateString_);
}

void PhilosopherItem::startPhilosopher()
{
    philosopher_->start();
}

void PhilosopherItem::onPhilosopherStateChanged(Philosopher::State state)
{
    switch (state) {
    case Philosopher::Eating:
        setPhilosopherStateString(EatingStateString);
        break;

    case Philosopher::Thinking:
        setPhilosopherStateString(ThinkingStateString);
        break;

    default:
        setPhilosopherStateString("Unknown");
        break;
    }
}
