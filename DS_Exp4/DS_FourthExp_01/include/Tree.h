#ifndef TREE_H
#define TREE_H
#include <stack>
#include <queue>
#include <iostream>

class Node
{
public:
    char data;
    Node* FirstChild;
    Node* NextBrother;
    Node(){FirstChild=NULL;NextBrother=NULL;data=0;}
    Node(char c){FirstChild=NULL;NextBrother=NULL;data=c;}
};

class Tree
{
    public:
        Tree();
        virtual ~Tree();
        Node* root;
        void CreateTree();
        Node* Create();
        void PreOrderR(Node* p);    //Recursive
        void PreOrderI();    //Iterative
        void PostOrderR(Node* p);
        void PostOrderI();
        void LevelOrder();
    protected:

    private:
        void IterateStack(std::stack<Node*>* s,Node* p);
};

#endif // TREE_H
