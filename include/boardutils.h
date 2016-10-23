#ifndef BOARDUTILS_H
#define BOARDUTILS_H
#include "board.h"
#include <vector>

class BoardUtils
{
public:
    BoardUtils();
    bool checkPlayerWon(const std::vector<std::vector<BoardField>>& board, BoardField boardField);
};

#endif // BOARDUTILS_H
