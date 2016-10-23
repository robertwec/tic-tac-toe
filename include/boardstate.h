#ifndef BOARDSTATE_H
#define BOARDSTATE_H
#include "board.h"
#include <vector>

class BoardState
{
public:
    BoardState(int boardSize);
    BoardState(std::vector< std::vector<BoardField> > board, int boardSize, int filledFields);
    std::vector<std::vector<BoardField> > getBoard() const;

    int getBoardSize() const;

    int getFilledFields() const;

private:
    std::vector< std::vector<BoardField> > board;
    int boardSize;
    int filledFields;
};

#endif // BOARDSTATE_H
