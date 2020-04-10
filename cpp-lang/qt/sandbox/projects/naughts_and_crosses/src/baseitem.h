#ifndef BASEITEM_H
#define BASEITEM_H

#include <QObject>

class BaseItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(int z READ z WRITE setZ NOTIFY zChanged)
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
public:
    explicit BaseItem(QObject *parent = nullptr);

    int x() const { return m_x; }
    int y() const { return m_y; }
    int z() const { return m_z; }
    int width() const { return m_width; }
    int height() const { return m_height; }

    void setX(int);
    void setY(int);
    void setZ(int);
    void setWidth(int);
    void setHeight(int);

signals:
    void xChanged(int);
    void yChanged(int);
    void zChanged(int);
    void widthChanged(int);
    void heightChanged(int);

private:
    int m_x;
    int m_y;
    int m_z;
    int m_width;
    int m_height;
};

#endif // BASEITEM_H
