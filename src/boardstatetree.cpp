#include "boardstatetree.h"

BoardStateTree::BoardStateTree()
{

}

void BoardStateTree::destroyTree()
{

}

Node *BoardStateTree::getRoot() const
{
    return root;
}

void BoardStateTree::setRoot(Node *value)
{
    root = value;
}
