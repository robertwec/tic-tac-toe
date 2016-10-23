#include "boardstatestreegenerator.h"


BoardStatesTreeGenerator::BoardStatesTreeGenerator(int maxDepth, int boardSize)
{
    this->maxDepth = maxDepth;
    this->boardSize = boardSize;
}

BoardStateTree BoardStatesTreeGenerator::generateStateTree()
{
    BoardStateTree boardStateTree;
    Node* root = new Node();
    BoardState boardState(boardSize);
    root.setBoardState(boardState);
    boardStateTree.setRoot(root);
    generateNextNodes(root, BoardField::FIRST_PLAYER);
    return boardStateTree;
}

void BoardStatesTreeGenerator::generateNextNodes(Node *currentNode, BoardField player)
{
    BoardState currentBoardState = currentNode->getBoardState();
    std::vector<std::vector<BoardField> > currentBoard = currentBoardState.getBoard();

    for(int x = 0; i < currentBoardState.getBoardSize(); ++x) {
        for (int y = 0; y < currentBoardState.getBoardSize(); ++y) {
            if(currentBoard[x][y] == BoardField::EMPTY) {
                std::vector<std::vector<BoardField> > newBoard = currentBoard;
                newBoard[x][y] = player;
                BoardState newBoardState(newboard, currentBoardState.getBoardSize(), currentBoardState.getFilledFields()+1);
                Node* newNode = new Node();
                newNode->setBoardState(newBoardState);
                currentNode->insert(newNode);
                if(!boardUtils.checkPlayerWon(newBoard, player) && newBoardState.getFilledFields() <= maxDepth) {
                    if(player == BoardField::FIRST_PLAYER) {
                        generateNextNodes(newNode, BoardField::SECOND_PLAYER);
                    } else {
                        generateNextNodes(newNode, BoardField::FIRST_PLAYER);
                    }
                }
            }
        }
    }
}
