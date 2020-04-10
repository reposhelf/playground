#include "myclass.h"

#include <QDebug>

MyClass::MyClass(QObject *parent)
    : QObject(parent),
      m_priority(Low),
      m_name()
{
    connect(this, &MyClass::nameChanged, this, &MyClass::checkName);
}

MyClass::~MyClass()
{
}

MyClass::Priority MyClass::priority() const
{
    return m_priority;
}

void MyClass::setPriority(MyClass::Priority priority)
{
    if (priority == m_priority)
        return;

    m_priority = priority;

    emit priorityChanged(m_priority);
}

QString MyClass::name() const
{
    return m_name;
}

void MyClass::setName(const QString &name)
{
    if (name == m_name)
        return;

    m_name = name;

    emit nameChanged(m_name);
}

void MyClass::checkName(const QString &name) const
{
    qDebug() << name;
}
