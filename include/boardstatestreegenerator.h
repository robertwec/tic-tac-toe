#ifndef BOARDSTATESTREEGENERATOR_H
#define BOARDSTATESTREEGENERATOR_H
#include "boardstatetree.h"
#include "boardutils.h"
#include "node.h"
#include "boardstate.h"

class BoardStatesTreeGenerator
{
public:
    BoardStatesTreeGenerator(int maxDepth, int boardSize);
    BoardStateTree generateStateTree();
private:
    void generateNextNodes(Node* currentNode, BoardField player);
    BoardUtils boardUtils;
    int maxDepth;
    int boardSize;
};

#endif // BOARDSTATESTREEGENERATOR_H
