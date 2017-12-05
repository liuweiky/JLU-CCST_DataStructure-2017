#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
    top=-1,size=20;
    StackArray=new int[size];
}

Stack::~Stack()
{
    //dtor
}

void Stack::Push(int i)
{
    top+=1;
    StackArray[top]=i;
}

int Stack::Pop()
{
    if(top==-1)
    {
        return 0;
    }
    int tmp=StackArray[top];
    top-=1;
    return tmp;
}

int Stack::Peek()
{
    return StackArray[top];
}

void Stack::Print()
{
    cout<<endl;
    for(int i=0;i<=top;i++)
    {
        cout<<'['<<StackArray[i]<<']';
        if(i!=top)
            cout<<"->";
    }
    cout<<endl;
}
