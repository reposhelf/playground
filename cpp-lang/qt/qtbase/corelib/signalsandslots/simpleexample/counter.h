#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT

public:
    explicit Counter(QObject *parent = 0);

    int value() const;

signals:
    void valueChanged(int);

public slots:
    void setValue(int value);

private:
    int m_value;
};

#endif // COUNTER_H
