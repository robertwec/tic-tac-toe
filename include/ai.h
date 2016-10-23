#ifndef AI_H
#define AI_H
#include <vector>
#include "board.h"

class Ai
{
public:
    Ai();
    BoardCoordinates select_field(const std::vector<std::vector<BoardField>>& board, BoardField human_field, BoardField computer_field);

private:
    BoardCoordinates select_random_field(int from, int to);
    bool check_is_empty(const std::vector<std::vector<BoardField>>& board);

    enum class Direction{ NO_DIRECTION, VERTICAL, HORIZONTAL, DIAGONAL_DOWN, DIAGONAL_UP };

    struct BoardCoordinatesPair{
        BoardCoordinates start;
        BoardCoordinates end;
        int length;
        Direction direction;
    };

    std::vector<BoardCoordinatesPair> find_longest_enemy_lines(const std::vector<std::vector<BoardField>>& board, BoardField human_field);
};

#endif // AI_H
