#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "board.h"
#include "result.h"
#include "square.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

    Board *board() const { return m_board; }
    Result *result() const { return m_result; }

private slots:
    void onSquareClicked();
    void changeSignsForPlayers();

private:
    void makeBoard();
    void makeBoardSquares();
    bool checkWin();
    bool checkDraw();
    void drawHorizontalLineRequest(int);
    void drawVerticalLineRequest(int);
    void drawDiagonalLineRequest(int);

    Board *m_board;
    Result *m_result;
    Square::SignFlags m_currentTurn;
};

#endif // CONTROLLER_H
