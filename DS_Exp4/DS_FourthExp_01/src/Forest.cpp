#include <iostream>
#include "Forest.h"

using namespace std;

Forest::Forest()
{
    TreeNum=0;
    VirtualRoot=NULL;
}

Forest::Forest(int n)
{
    TreeNum=n;
    Node* TreeArr[n];
    for(int i=0;i<n;i++)
    {
        Tree* t=new Tree();
        t->CreateTree();
        TreeArr[i]=t->root;
    }
    VirtualRoot=TreeArr[0];
    for(int i=0;i<n-1;i++)
    {
        TreeArr[i]->NextBrother=TreeArr[i+1];
    }
}

Forest::~Forest()
{
    //dtor
}

void Forest::PreOrderR(Node* p)
{
    if(p==NULL)
    {
        return;
    }
    cout<<p->data;
    PreOrderR(p->FirstChild);
    PreOrderR(p->NextBrother);
}

void Forest::PreOrderI()
{
    stack<Node*>* s=new stack<Node*>();
    s->push(VirtualRoot);
    while(!s->empty())
    {
        Node* p=s->top();
        s->pop();
        cout<<p->data;
        if(p->NextBrother!=NULL)
        {
            s->push(p->NextBrother);
        }
        if(p->FirstChild!=NULL)
        {
            s->push(p->FirstChild);
        }
    }
}

void Forest::PostOrderR(Node *p)
{
    if(p!=NULL)
    {
        PostOrderR(p->FirstChild);
        cout<<p->data;
        PostOrderR(p->NextBrother);
    }
}

void Forest::PostOrderI()
{
    Node* p=VirtualRoot;
    stack<Node*>* s=new stack<Node*>();
    IterateStack(s,p);
    while(!s->empty())
    {
        p=s->top();
        s->pop();
        cout<<p->data;
        IterateStack(s,p->NextBrother);

    }
}

void Forest::IterateStack(stack<Node*>* s,Node* p)
{
    while(p!=NULL)
    {
        s->push(p);
        p=p->FirstChild;
    }
}

void Forest::LevelOrder()
{
    queue<Node*>* q=new queue<Node*>();
    q->push(VirtualRoot);
    while(!q->empty())
    {
        Node* p=q->front();
        q->pop();
        while(p!=NULL)
        {
            cout<<p->data;
            if(p->FirstChild!=NULL)
            {
                q->push(p->FirstChild);
            }
            p=p->NextBrother;
        }
    }
}
