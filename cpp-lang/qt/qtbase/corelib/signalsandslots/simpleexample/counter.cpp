#include "counter.h"

Counter::Counter(QObject *parent)
    : QObject(parent),
      m_value(0)
{
}

int Counter::value() const
{
    return m_value;
}

void Counter::setValue(int value)
{
    if (m_value != value) {
        m_value = value;
        emit valueChanged(m_value);
    }
}
