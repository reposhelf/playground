#ifndef BOARD_H
#define BOARD_H

#include <QQmlListProperty>

#include "baseitem.h"
#include "square.h"

class Board : public BaseItem
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Square> squaresProperty READ squaresProperty CONSTANT)
public:
    Board(int rowsCount, int colsCount, QObject *parent = nullptr);

    QQmlListProperty<Square> squaresProperty();

    Square *square(int, int) const;
    void addSquare(Square *);

public slots:
    void reset();

signals:
    void drawLineRequest(int x, int y, int w, int h, int r);
    void resetted();
    void newSignPlaced();

private:
    QList<Square *> m_squares;
    int m_rowsCount;
    int m_colsCount;
};

#endif // BOARD_H
