#ifndef BOARDSTATE_H
#define BOARDSTATE_H
#include"board.h"
#include<vector>

class BoardState
{
public:
    BoardState();
private:
    std::vector< std::vector<BoardField> > board;
};

#endif // BOARDSTATE_H
