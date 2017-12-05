#ifndef FOREST_H
#define FOREST_H
#include "Tree.h"
#include <stack>
#include <queue>

class Forest
{
    public:
        Forest();
        Forest(int n);
        virtual ~Forest();
        int TreeNum;
        Node* VirtualRoot;
        void PreOrderR(Node* p);    //Recursive
        void PreOrderI();    //Iterative
        void PostOrderR(Node* p);
        void PostOrderI();
        void LevelOrder();
    protected:

    private:
        void IterateStack(std::stack<Node*>* s,Node* p);
};

#endif // FOREST_H
