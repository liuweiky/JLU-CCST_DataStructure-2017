#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
    top=-1,size=20;
    StackArray=new char[size];
}

Stack::~Stack()
{
    //dtor
}

void Stack::Push(char i)
{
    top+=1;
    StackArray[top]=i;
}

char Stack::Pop()
{
    if(top==-1) return ' ';
    char tmp=StackArray[top];
    top-=1;
    return tmp;
}

char Stack::Peek()
{
    if(top==-1) return ' ';
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

int Stack::GetTop()
{
    return top;
}
