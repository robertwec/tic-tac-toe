#include "logic.h"
#include <ncurses.h>

Logic::Logic()
{
    board = std::vector< std::vector<BoardField> > (
                BOARD_SIZE, std::vector<BoardField>(BOARD_SIZE, BoardField::EMPTY));
    current_player = 0;
    show_selected = true;
    selected_field = {0, 0};
    players_list = {{PlayerType::HUMAN, BoardField::X}, {PlayerType::HUMAN, BoardField::O}};
    game_finished = false;
    winner = nullptr;
}

void Logic::update(int pressed_key)
{
    if(game_finished) {
        return;
    }
    show_selected = true;
    switch(pressed_key) {
        case KEY_LEFT:
            if(selected_field.x > 0) {
                selected_field.x--;
            }
            break;
        case KEY_RIGHT:
            if(selected_field.x < (BOARD_SIZE-1)) {
                selected_field.x++;
            }
            break;
        case KEY_UP:
            if(selected_field.y > 0) {
                selected_field.y--;
            }
            break;
        case KEY_DOWN:
            if(selected_field.y < (BOARD_SIZE-1)) {
                selected_field.y++;
            }
            break;
        case ' ':
            if(board[selected_field.x][selected_field.y] != BoardField::EMPTY) {
                return;
            }
            show_selected = false;
            first_player_move();
            if(game_finished) {
                return;
            }
            second_player_move();

            break;
        default:
            break;
    }
}

int Logic::get_board_size()
{
    return BOARD_SIZE;
}

std::vector<std::vector<BoardField> > Logic::getBoard() const
{
    return board;
}

BoardCoordinates Logic::getSelected_field() const
{
    return selected_field;
}

void Logic::change_turn()
{
    current_player++;
    if(current_player == players_list.size()) {
        current_player = 0;
    }
}

void Logic::first_player_move()
{
    board[selected_field.x][selected_field.y] = players_list[current_player].field_type;
    check_game_finished(players_list[current_player]);
}

void Logic::second_player_move()
{
    change_turn();
    if(players_list[current_player].player_type == PlayerType::HUMAN) {
        return;
    }
    //BoardCoordinates computer_selected_field = computer_player.select_field(const_cast<const std::vector<std::vector<BoardField>>&>(board));
    //board[computer_selected_field.x][computer_selected_field.y] = players_list[current_player].field_type;
    check_game_finished(players_list[current_player]);
    change_turn();
}

void Logic::check_game_finished(const Player &player)
{
    for(int x=0; x<BOARD_SIZE; x++) {
        for(int y=0; y<BOARD_SIZE; y++) {
            if(board[x][y] != player.field_type) {
                break;
            } else if(y == (BOARD_SIZE-1)) {
                game_finished = true;
                winner = const_cast<Player *>(&player);
                return;
            }
        }
    }

    for(int y=0; y<BOARD_SIZE; y++) {
        for(int x=0; x<BOARD_SIZE; x++) {
            if(board[x][y] != player.field_type) {
                break;
            } else if(x == (BOARD_SIZE-1)) {
                game_finished = true;
                winner = const_cast<Player *>(&player);
                return;
            }
        }
    }

    for(int x=0; x<BOARD_SIZE; x++) {
        int y = x;
        if(board[x][y] != player.field_type) {
            break;
        } else if(y == (BOARD_SIZE-1)) {
            game_finished = true;
            winner = const_cast<Player *>(&player);
            return;
        }
    }

    for(int y=(BOARD_SIZE-1); y>=0; y--) {
        int x = y;
        if(board[x][y] != player.field_type) {
            break;
        } else if(x == 0) {
            game_finished = true;
            winner = const_cast<Player *>(&player);
            return;
        }
    }

}
