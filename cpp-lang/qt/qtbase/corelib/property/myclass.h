#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Priority priority READ priority WRITE setPriority NOTIFY priorityChanged)
    Q_PROPERTY(QString name NOTIFY nameChanged)

public:
    MyClass(QObject *parent = Q_NULLPTR);
    ~MyClass();

    enum Priority {
        High, Low, VeryHigh, VeryLow
    };
    Q_ENUM(Priority)

    Priority priority() const;
    void setPriority(Priority priority);

    QString name() const;
    void setName(const QString &name);

signals:
    void priorityChanged(Priority);
    void nameChanged(const QString&);

private slots:
    void checkName(const QString &name) const;

private:
    Priority m_priority;
    QString m_name;
};

#endif // MYCLASS_H
