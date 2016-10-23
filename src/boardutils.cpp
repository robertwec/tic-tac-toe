#include "boardutils.h"

BoardUtils::BoardUtils()
{

}

bool BoardUtils::checkPlayerWon(const std::vector<std::vector<BoardField> > &board, BoardField boardField)
{
    for(int x=0; x < board.size(); x++) {
        for(int y=0; y < board.size(); y++) {
            if(board[x][y] != boardField) {
                break;
            } else if(y == (board.size()-1)) {
                return true;
            }
        }
    }

    for(int y=0; y < board.size(); y++) {
        for(int x=0; x < board.size(); x++) {
            if(board[x][y] != boardField) {
                break;
            } else if(x == (board.size()-1)) {
                return true;
            }
        }
    }

    for(int x=0; x < board.size(); x++) {
        int y = x;
        if(board[x][y] != boardField) {
            break;
        } else if(y == (board.size()-1)) {
            return true;
        }
    }

    for(int y=(board.size()-1); y>=0; y--) {
        int x = y;
        if(board[x][y] != boardField) {
            break;
        } else if(x == 0) {
            return true;
        }
    }
}
