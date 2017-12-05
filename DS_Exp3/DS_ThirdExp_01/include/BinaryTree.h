#ifndef BINARYTREE_H
#define BINARYTREE_H

class Node
{
public:
    char data;
    Node* Left;
    Node* Right;
    Node(){Left=NULL;Right=NULL;}
    Node(char c){Left=NULL;Right=NULL;data=c;}
};

class BinaryTree
{
    public:
        BinaryTree();
        virtual ~BinaryTree();
        Node* root;
        void CreateTree();
        void PreOrder(Node* p);
        void InOrder(Node* p);
        void PostOrder(Node* p);
        Node* GetFather(Node* p);
        Node* GetFather(char ch);
        Node* Find(char ch);
        bool IsComplete();
    protected:

    private:
        Node* Create();
};

#endif // BINARYTREE_H
