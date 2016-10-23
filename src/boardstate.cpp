#include "boardstate.h"

BoardState::BoardState(int board_size)
{
    this->board = std::vector< std::vector<BoardField> > (
                board_size, std::vector<BoardField>(board_size, BoardField::EMPTY));
    this->boardSize = board_size;
    this->filledFields = 0;
}

BoardState::BoardState(std::vector<std::vector<BoardField> > board, int board_size, int filled_fields)
{
    this->board = board;
    this->boardSize = board_size;
    this->filledFields = filled_fields;
}

std::vector<std::vector<BoardField> > BoardState::getBoard() const
{
    return board;
}

int BoardState::getBoardSize() const
{
    return boardSize;
}

int BoardState::getFilledFields() const
{
    return filledFields;
}

int BoardState::getFirstPlayerFields() const
{
    return firstPlayerFields;
}

int BoardState::getSecondPlayerFields() const
{
    return secondPlayerFields;
}
