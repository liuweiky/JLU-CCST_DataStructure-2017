#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
    front=NULL;rear=NULL;
}

Queue::~Queue()
{
    //dtor
}

void Queue::Insert(int i)
{
    Node* n=new Node(i);
    if(front==NULL)
        front=n;
    else rear->Next=n;
    rear=n;
}

int Queue::Delete()
{
    if(front!=NULL)
    {
        int tmp=front->data;
        Node* n=front;
        front=front->Next;
        delete n;
        return tmp;
    }
    return 0;
}

int Queue::Front()
{
    return front->data;
}

void Queue::Print()
{
    cout<<endl;
    Node* p=front;
    while(p!=NULL)
    {
        cout<<'['<<p->data<<']';
        if(p!=rear)
            cout<<"->";
        p=p->Next;
    }
    cout<<endl;
}
