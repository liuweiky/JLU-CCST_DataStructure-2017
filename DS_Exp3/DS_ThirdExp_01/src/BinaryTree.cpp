#include <iostream>
#include <queue>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree()
{
    root=NULL;
}

BinaryTree::~BinaryTree()
{
    //dtor
}

void BinaryTree::CreateTree()
{
    root=Create();
}

Node* BinaryTree::Create()
{
    char ch;
    cin>>ch;
    if(ch=='#')
    {
        return NULL;
    }else{
        Node* p=new Node(ch);
        p->Left=Create();
        p->Right=Create();
        return p;
    }
}

/**Method 2*/
/*void BinaryTree::CreateTree(Node*& p) //Note: Use &
{
    char ch;
    cin>>ch;
    if(ch=='#')
    {
        p=NULL;
        return;
    }else{
        p=new Node(ch);
        CreateTree(p->Left);
        CreateTree(p->Right);
    }
}*/

void BinaryTree::PreOrder(Node* p)
{
    if(p!=NULL)
    {
        cout<<p->data;
        PreOrder(p->Left);
        PreOrder(p->Right);
    }
}

void BinaryTree::InOrder(Node* p)
{
    if(p!=NULL)
    {
        InOrder(p->Left);
        cout<<p->data;
        InOrder(p->Right);
    }
}

void BinaryTree::PostOrder(Node* p)
{
    if(p!=NULL)
    {
        PostOrder(p->Left);
        PostOrder(p->Right);
        cout<<p->data;
    }
}

Node* BinaryTree::GetFather(Node* s)
{
    if(s!=NULL)
    {
        queue<Node*>* q=new queue<Node*>();
        q->push(root);
        while(!q->empty())
        {
            Node* p=q->front();
            q->pop();
            if(p->Left==s||p->Right==s)
            {
                return p;
            }
            if(p->Left!=NULL)
            {
                q->push(p->Left);
            }
            if(p->Right!=NULL)
            {
                q->push(p->Right);
            }
        }
    }else return NULL;
    return NULL;
}

Node* BinaryTree::GetFather(char ch)
{
    return GetFather(Find(ch));
}

Node* BinaryTree::Find(char ch)
{
    if(root!=NULL)
    {
        queue<Node*>* q=new queue<Node*>();
        q->push(root);
        while(!q->empty())
        {
            Node* p=q->front();
            q->pop();
            if(p!=NULL&&p->data==ch)
            {
                return p;
            }
            if(p->Left!=NULL)
            {
                q->push(p->Left);
            }
            if(p->Right!=NULL)
            {
                q->push(p->Right);
            }
        }
    }
    return NULL;
}

bool BinaryTree::IsComplete()
{
    bool flag=false;
    queue<Node*>* q=new queue<Node*>();
    q->push(root);
    while(!q->empty())
    {
        Node* p=q->front();
        q->pop();
        if(p==NULL)
        {
            flag=true;
        }
        if(flag&&p!=NULL)
        {
            return false;
        }
        /**Null q Being Pushed Causes Null Pointer*/
        if(p!=NULL)
        {
            q->push(p->Left);
            q->push(p->Right);
        }
    }
    return true;
}
