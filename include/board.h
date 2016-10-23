#ifndef BOARD_H
#define BOARD_H

struct BoardCoordinates{
    int x;
    int y;
};

enum class BoardField { EMPTY, X, O };

#endif // BOARD_H
