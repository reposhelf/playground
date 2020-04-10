#include "baseitem.h"

BaseItem::BaseItem(QObject *parent)
    : QObject(parent),
      m_x(0),
      m_y(0),
      m_z(0),
      m_width(0),
      m_height(0)
{
}

void BaseItem::setX(int x)
{
    if (m_x == x)
        return;
    m_x = x;
    emit xChanged(m_x);
}

void BaseItem::setY(int y)
{
    if (m_y == y)
        return;
    m_y = y;
    emit yChanged(m_y);
}

void BaseItem::setZ(int z)
{
    if (m_z == z)
        return;
    m_z = z;
    emit zChanged(m_z);
}

void BaseItem::setWidth(int width)
{
    if (m_width == width)
        return;
    m_width = width;
    emit widthChanged(m_width);
}

void BaseItem::setHeight(int height)
{
    if (m_height == height)
        return;
    m_height = height;
    emit heightChanged(m_height);
}
