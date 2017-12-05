#include "Tree.h"

using namespace std;

Tree::Tree()
{
    root=NULL;
}

Tree::~Tree()
{
    //dtor
}

void Tree::CreateTree()
{
    root=Create();
}

Node* Tree::Create()
{
    char ch;
    cin>>ch;
    if(ch=='#')
    {
        return NULL;
    }else
    {
        Node* p=new Node(ch);
        p->FirstChild=Create();
        p->NextBrother=Create();
        return p;
    }
}

void Tree::PreOrderR(Node* p)
{
    if(p==NULL)
    {
        return;
    }
    cout<<p->data;
    PreOrderR(p->FirstChild);
    PreOrderR(p->NextBrother);
}

void Tree::PreOrderI()
{
    stack<Node*>* s=new stack<Node*>();
    s->push(root);
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

void Tree::PostOrderR(Node *p)
{
    if(p!=NULL)
    {
        PostOrderR(p->FirstChild);
        cout<<p->data;
        PostOrderR(p->NextBrother);
    }
}

void Tree::PostOrderI()
{
    Node* p=root;
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

void Tree::IterateStack(stack<Node*>* s,Node* p)
{
    while(p!=NULL)
    {
        s->push(p);
        p=p->FirstChild;
    }
}


void Tree::LevelOrder()
{
    queue<Node*>* q=new queue<Node*>();
    q->push(root);
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
