#include "ai.h"
#include<random>

Ai::Ai()
{

}

//BoardCoordinates Ai::select_field(const std::vector<std::vector<BoardField> > &board, BoardField human_field, BoardField computer_field)
//{
//    if(check_is_empty(board)) {
//        return select_random_field(0, board.size()-1);
//    }

//}

//BoardCoordinates Ai::select_random_field(int from, int to)
//{
//    BoardCoordinates coordinates;
//    std::random_device random_device;
//    std::mt19937 mersenne_twister(random_device());
//    std::uniform_int_distribution<> distribution(from, to);

//    coordinates.x = distribution(mersenne_twister);
//    coordinates.y = distribution(mersenne_twister);

//    return coordinates;
//}

//bool Ai::check_is_empty(const std::vector<std::vector<BoardField> > &board)
//{
//    bool is_empty = true;

//    for(int x=0; x<board.size(); x++) {
//        for(int y=0; y<board.size(); y++) {
//            if(board[x][y] != BoardField::EMPTY) {
//                is_empty = false;
//                break;
//            }
//        }
//    }

//    return is_empty;
//}

//std::vector<Ai::BoardCoordinatesPair> Ai::find_longest_enemy_lines(const std::vector<std::vector<BoardField> > &board, BoardField human_field)
//{
//    int longest_line_size = 0;
//    int current_line_size = 0;

//    std::vector<BoardCoordinatesPair> board_coordinates_pairs;

//    BoardCoordinatesPair coordinates_pair = {{0,0}, {0,0}, 0, Direction::NO_DIRECTION};

//    for(int x=0; x<board.size(); x++) {
//        for(int y=0; y<board.size(); y++) {
//            if(board[x][y] == human_field) {
//                current_line_size++;
//                if(current_line_size == 1) {
//                    coordinates_pair.start.x = x;
//                    coordinates_pair.start.y = y;
//                    coordinates_pair.direction = Direction::NO_DIRECTION;
//                } else {
//                    coordinates_pair.end.x = x;
//                    coordinates_pair.end.y = y;
//                    coordinates_pair.direction = Direction::VERTICAL;
//                }
//            }
//            if(y == (board.size()-1)) {
//                coordinates_pair.length = current_line_size;
//                if(current_line_size > longest_line_size) {

//                } else if(current_line_size == longest_line_size) {

//                }
//            }
//        }
//    }

//    for(int y=0; y<board.size(); y++) {
//        for(int x=0; x<board.size(); x++) {
//            if(board[x][y] != player.field_type) {
//                break;
//            } else if(x == (BOARD_SIZE-1)) {
//                game_finished = true;
//                winner = const_cast<Player *>(&player);
//                return;
//            }
//        }
//    }

//    for(int x=0; x<board.size(); x++) {
//        int y = x;
//        if(board[x][y] != player.field_type) {
//            break;
//        } else if(y == (BOARD_SIZE-1)) {
//            game_finished = true;
//            winner = const_cast<Player *>(&player);
//            return;
//        }
//    }

//    for(int y=(board.size()-1); y>=0; y--) {
//        int x = y;
//        if(board[x][y] != player.field_type) {
//            break;
//        } else if(x == 0) {
//            game_finished = true;
//            winner = const_cast<Player *>(&player);
//            return;
//        }
//    }
//}
