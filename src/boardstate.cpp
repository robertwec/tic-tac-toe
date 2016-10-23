#include "boardstate.h"

BoardState::BoardState()
{
    board = std::vector< std::vector<BoardField> > (
                BOARD_SIZE, std::vector<BoardField>(BOARD_SIZE, BoardField::EMPTY));
}
