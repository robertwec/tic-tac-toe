#ifndef BOARD_H
#define BOARD_H

struct BoardCoordinates{
    int x;
    int y;
};

enum class BoardField { EMPTY, FIRST_PLAYER, SECOND_PLAYER };

#endif // BOARD_H
