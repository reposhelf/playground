#ifndef PHILOSOPHERITEM_H
#define PHILOSOPHERITEM_H

#include <QObject>

#include "philosopher.h"
#include "table.h"

class PhilosopherItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString philosopherName READ philosopherName WRITE setPhilosopherName
               NOTIFY philosopherNameChanged)
    Q_PROPERTY(int x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(QString philosopherStateString READ philosopherStateString
               WRITE setPhilosopherStateString NOTIFY philosopherStateStringChanged)
    Q_PROPERTY(int id READ id CONSTANT)
public:
    PhilosopherItem(const QString &name, Table *table, QObject *parent = nullptr);
    ~PhilosopherItem();

    QString philosopherName() const;
    void setPhilosopherName(const QString &name);

    int x() const { return x_; }
    void setX(int x);

    int y() const { return y_; }
    void setY(int y);

    int width() const { return width_; }
    void setWidth(int width);

    int height() const { return height_; }
    void setHeight(int height);

    QString philosopherStateString() const { return philosopherStateString_; }
    void setPhilosopherStateString(const QString &stateStr);

    int id() const { return id_; }

    void startPhilosopher();

signals:
    void philosopherNameChanged(const QString&);
    void xChanged(int);
    void yChanged(int);
    void widthChanged(int);
    void heightChanged(int);
    void stopPhilosopherRequest();
    void pausePhilosopherRequest(bool);
    void philosopherStateStringChanged(const QString&);

private slots:
    void onPhilosopherStateChanged(Philosopher::State state);

private:
    Philosopher *philosopher_;
    int x_ = 0;
    int y_ = 0;
    int width_ = 0;
    int height_ = 0;
    int id_ = 0;
    QString philosopherStateString_;
};

#endif // PHILOSOPHERITEM_H
