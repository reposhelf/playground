#include "controller.h"

#include <cmath>

namespace
{
const int BOARD_SPACING = 2;
const int BOARD_SPACERS_COUNT = 4;

const int BOARD_ROWS_COUNT = 3;
const int BOARD_COLS_COUNT = 3;

const int SQUARE_WIDTH = 150;
const int SQUARE_HEIGHT = 150;

const int BOARD_WIDTH = BOARD_SPACING * BOARD_SPACERS_COUNT + SQUARE_WIDTH * BOARD_COLS_COUNT;
const int BOARD_HEIGHT = BOARD_SPACING * BOARD_SPACERS_COUNT + SQUARE_HEIGHT * BOARD_ROWS_COUNT;

const qreal LINE_WIDTH_COEFFICIENT = 0.05;

int distance(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2;
    int dy = y1 - y2;

    return std::sqrt(dx * dx + dy * dy);
}
}

Controller::Controller(QObject *parent)
    : QObject(parent),
      m_board(nullptr),
      m_result(new Result(this)),
      m_currentTurn(Square::SignX)
{
    makeBoard();

    connect(m_result, SIGNAL(roundFinished(QString)), this, SLOT(changeSignsForPlayers()));
}

void Controller::onSquareClicked()
{
    Square *square = qobject_cast<Square *>(sender());
    if (square == nullptr)
        return;

    if (square->signFlag() != Square::SignNone)
        return;

    square->setSignFlag(m_currentTurn);

    if (checkWin())
    {
        QString winnerName;
        if (m_currentTurn == Square::SignX)
        {
            m_result->setFirstPlayerScore(m_result->firstPlayerScore() + 1.0);
            winnerName = m_result->firstPlayerName();
        }
        else if (m_currentTurn == Square::SignO)
        {
            winnerName = m_result->secondPlayerName();
            m_result->setSecondPlayerScore(m_result->secondPlayerScore() + 1.0);
        }
        m_currentTurn = Square::SignX;

        const QString roundResultMsg = "<b>"
                + winnerName + "</b><br>"
                + "<b>WIN!</b>";

        emit m_result->roundFinished(roundResultMsg);
        return;
    }

    if (checkDraw())
    {
        m_result->setFirstPlayerScore(m_result->firstPlayerScore() + 0.5);
        m_result->setSecondPlayerScore(m_result->secondPlayerScore() + 0.5);
        m_currentTurn = Square::SignX;
        emit m_result->roundFinished("<b>DRAW</>");
        return;
    }

    m_currentTurn ^= Square::SignMask;
    emit m_board->newSignPlaced();
}

void Controller::changeSignsForPlayers()
{
    QString firstPlayerName = m_result->firstPlayerName();
    qreal firstPlayerScore = m_result->firstPlayerScore();

    m_result->setFirstPlayerName(m_result->secondPlayerName());
    m_result->setFirstPlayerScore(m_result->secondPlayerScore());

    m_result->setSecondPlayerName(firstPlayerName);
    m_result->setSecondPlayerScore(firstPlayerScore);
}

void Controller::makeBoard()
{
    m_board = new Board(BOARD_ROWS_COUNT, BOARD_COLS_COUNT, this);
    m_board->setWidth(BOARD_WIDTH);
    m_board->setHeight(BOARD_HEIGHT);

    makeBoardSquares();
}

void Controller::makeBoardSquares()
{
    for (int row = 0, currY = BOARD_SPACING; row != BOARD_ROWS_COUNT;
         ++row, currY += SQUARE_HEIGHT + BOARD_SPACING)
    {
        for (int col = 0, currX = BOARD_SPACING; col != BOARD_COLS_COUNT;
             ++col, currX += SQUARE_WIDTH + BOARD_SPACING)
        {
            auto square = new Square(m_board);

            square->setWidth(SQUARE_WIDTH);
            square->setHeight(SQUARE_HEIGHT);

            square->setX(currX);
            square->setY(currY);

            connect(square, SIGNAL(clicked()), this, SLOT(onSquareClicked()));

            m_board->addSquare(square);
        }
    }
}

bool Controller::checkWin()
{
    // horizontal
    for (int row = 0; row != BOARD_ROWS_COUNT; ++row)
    {
        if (m_board->square(row, 0)->signFlag() != Square::SignNone)
        {
            if ((m_board->square(row, 0)->signFlag()
                 == m_board->square(row, 1)->signFlag())
                    && (m_board->square(row, 1)->signFlag()
                        == m_board->square(row, 2)->signFlag()))
            {
                drawHorizontalLineRequest(row);
                return true;
            }
        }
    }

    // vertical
    for (int col = 0; col != BOARD_COLS_COUNT; ++col)
    {
        if (m_board->square(0, col)->signFlag() != Square::SignNone)
        {
            if ((m_board->square(0, col)->signFlag()
                 == m_board->square(1, col)->signFlag())
                    && (m_board->square(1, col)->signFlag()
                        == m_board->square(2, col)->signFlag()))
            {
                drawVerticalLineRequest(col);
                return true;
            }
        }
    }

    // diagonal
    if (m_board->square(0, 0)->signFlag() != Square::SignNone)
    {
        if ((m_board->square(0,0)->signFlag()
             == m_board->square(1, 1)->signFlag())
                && (m_board->square(1, 1)->signFlag()
                    == m_board->square(2, 2)->signFlag()))
        {
            drawDiagonalLineRequest(45);
            return true;
        }
    }

    if (m_board->square(0, 2)->signFlag() != Square::SignNone)
    {
        if ((m_board->square(0,2)->signFlag()
             == m_board->square(1, 1)->signFlag())
                && (m_board->square(1, 1)->signFlag()
                    == m_board->square(2, 0)->signFlag()))
        {
            drawDiagonalLineRequest(135);
            return true;
        }
    }

    return false;
}

bool Controller::checkDraw()
{
    for (int row = 0; row != BOARD_ROWS_COUNT; ++row)
    {
        for (int col = 0; col != BOARD_COLS_COUNT; ++col)
        {
            if (m_board->square(row, col)->signFlag() == Square::SignNone)
                return false;
        }
    }
    return true;
}

void Controller::drawHorizontalLineRequest(int row)
{
    const int lineWidth = BOARD_WIDTH - BOARD_SPACERS_COUNT;
    const int lineHeight = BOARD_HEIGHT * LINE_WIDTH_COEFFICIENT;
    const int lineX = BOARD_SPACING;
    const int lineY = (row + 1) * BOARD_SPACING
            + row * SQUARE_HEIGHT
            + SQUARE_HEIGHT / 2 - lineHeight / 2;
    const int lineRotation = 0;
    emit m_board->drawLineRequest(lineX, lineY, lineWidth, lineHeight, lineRotation);
}

void Controller::drawVerticalLineRequest(int col)
{
    const int lineWidth = BOARD_WIDTH * LINE_WIDTH_COEFFICIENT;
    const int lineHeight = BOARD_HEIGHT - BOARD_SPACERS_COUNT;
    const int lineY = BOARD_SPACING;
    const int lineX = (col + 1) * BOARD_SPACING
            + col * SQUARE_WIDTH
            + SQUARE_WIDTH / 2 - lineWidth / 2;
    const int lineRotation = 0;
    emit m_board->drawLineRequest(lineX, lineY, lineWidth, lineHeight, lineRotation);
}

void Controller::drawDiagonalLineRequest(int rotation)
{
    const int lineWidth = distance(BOARD_SPACING, BOARD_SPACING, BOARD_WIDTH, BOARD_HEIGHT)
            - BOARD_SPACING * 5;
    const int lineHeight = BOARD_HEIGHT * LINE_WIDTH_COEFFICIENT;
    const int lineX = BOARD_SPACING - (lineWidth - BOARD_WIDTH) / 2;
    const int midRow = 1;
    const int lineY = (midRow + 1) * BOARD_SPACING
            + midRow * SQUARE_HEIGHT
            + SQUARE_HEIGHT / 2 - lineHeight / 2;
    emit m_board->drawLineRequest(lineX, lineY, lineWidth, lineHeight, rotation);
}
