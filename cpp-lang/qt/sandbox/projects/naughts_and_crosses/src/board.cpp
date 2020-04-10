#include "board.h"

Board::Board(int rowsCount, int colsCount, QObject *parent)
    : BaseItem(parent),
      m_rowsCount(rowsCount),
      m_colsCount(colsCount)
{
}

QQmlListProperty<Square> Board::squaresProperty()
{
    return QQmlListProperty<Square>(this, m_squares);
}

Square *Board::square(int row, int col) const
{
    const int index = col + row * m_colsCount;
    if (index < 0 || index >= m_squares.count())
        return nullptr;
    return m_squares.at(index);
}

void Board::addSquare(Square *square)
{
    if (square == nullptr)
        return;
    m_squares.push_back(square);
    square->setParent(this);
}

void Board::reset()
{
    for (auto square : m_squares)
        square->setSignFlag(Square::SignNone);
    emit resetted();
}
