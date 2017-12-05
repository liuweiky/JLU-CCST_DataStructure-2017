#include <iostream>
#include "List.h"
#include "Stack.h"

using namespace std;

List::List()
{
    head=new Node();
    head->Next=head;
    tail=head;
}

List::~List()
{
    //dtor
}

void List::Insert(char ch)
{
    Node* n=new Node(ch);
    if(head->Next==head)
    {
        head->Next=n;
    }
    tail->Next=n;
    tail=n;
    n->Next=head;
}

int List::Check()
{
    Stack* stack=new Stack();
    Node* p=head;
    while(p->Next!=head)
    {
        p=p->Next;
        switch(stack->Peek())
        {
        case '[':
            if(p->data==']')
            {
                stack->Pop();
            }else
            {
                stack->Push(p->data);
            }
            break;
        case '{':
            if(p->data=='}')
            {
                stack->Pop();
            }else
            {
                stack->Push(p->data);
            }
            break;
        case '(':
            if(p->data==')')
            {
                stack->Pop();
            }else
            {
                stack->Push(p->data);
            }
            break;
        default:
            stack->Push(p->data);
        }


    }
    return stack->GetTop();
}
