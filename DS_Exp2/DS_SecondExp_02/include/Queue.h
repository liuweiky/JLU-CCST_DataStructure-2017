#ifndef QUEUE_H
#define QUEUE_H

class Node
{
public:
    Node* Next;
    int data;
    Node(){Next=NULL;data=0;}
    Node(int i){Next=NULL;data=i;}
};

class Queue
{
    public:
        Queue();
        virtual ~Queue();
        void Insert(int i);
        int Delete();
        int Front();
        void Print();
        Node* front;
    protected:

    private:

        Node* rear;
};

#endif // QUEUE_H
