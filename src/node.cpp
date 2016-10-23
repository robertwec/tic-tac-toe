#include "node.h"

Node::Node()
{

}

std::list<Node *> Node::getNodeList() const
{
    return nodeList;
}

std::list<Node *> Node::getNodeList() const
{
    return nodeList;
}

BoardState Node::getBoardState() const
{
    return boardState;
}

void Node::setBoardState(const BoardState &value)
{
    boardState = value;
}
