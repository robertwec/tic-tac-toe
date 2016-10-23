#ifndef LOGIC_H
#define LOGIC_H

#include <vector>
//#include "ai.h"
#include "board.h"


class Logic
{
public:
    Logic();
    void update(int pressed_key);

    enum class PlayerType { HUMAN, COMPUTER };

    struct Player{
        PlayerType player_type;
        BoardField field_type;

    };

    static int get_board_size();

    std::vector<std::vector<BoardField> > getBoard() const;

    BoardCoordinates getSelected_field() const;

private:
    static const int BOARD_SIZE = 3;

    std::vector< std::vector<BoardField> > board;
    std::vector<Player> players_list;
    int current_player;
    bool show_selected;
    bool game_finished;
    Player* winner;

    BoardCoordinates selected_field;
    //Ai computer_player;

    void change_turn();
    void first_player_move();
    void second_player_move();
    void check_game_finished(const Player &player);
};

#endif // LOGIC_H
