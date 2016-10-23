#ifndef NODE_H
#define NODE_H
#include<list>
#include "boardstate.h"

class Node
{
public:
    Node();
    std::list<Node *> getNodeList() const;
    void insert(Node* node);
    BoardState getBoardState() const;
    void setBoardState(const BoardState &value);

private:
    std::list<Node*> nodeList;
    BoardState boardState;
};

#endif // NODE_H
