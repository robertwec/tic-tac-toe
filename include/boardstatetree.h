#ifndef BOARDSTATETREE_H
#define BOARDSTATETREE_H


class BoardStateTree
{
public:
    BoardStateTree();
    void destroyTree();

    Node *getRoot() const;
    void setRoot(Node *value);

private:
    Node* root;
};

#endif // BOARDSTATETREE_H
