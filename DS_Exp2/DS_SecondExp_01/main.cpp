#include <iostream>
#include <Stack.h>

using namespace std;

void ShowMenu(int i);

int main()
{
    Stack* stack=new Stack();
    ShowMenu(0);

    int operation=0;
    cin>>operation;

    while(operation)
    {
        int in;
        switch(operation)
        {
        case 1:
            ShowMenu(1);
            cin>>in;
            stack->Push(in);
            break;
        case 2:
            stack->Pop();
            break;
        case 3:
            if(stack->top!=-1)
            cout<<endl<<'['<<stack->Peek()<<']'<<endl;
            break;
        case 4:
            stack->Print();
            break;
        }
        ShowMenu(0);
        cin>>operation;
    }

    return 0;
}


void ShowMenu(int i)
{
    switch(i)
    {
    case 0:
        cout<<endl<<"ÇëÊäÈë²Ù×÷£º";
        cout<<endl<<"1) Ñ¹Õ»"<<endl<<"2) µ¯Õ»"<<endl<<"3) ¶ÁÈ¡Õ»¶¥"<<endl<<"4) ÏÔÊ¾Õ»ÄÚ×´¿ö"<<endl<<"0) ÍË³ö"<<endl<<endl;
        break;
    case 1:
        cout<<endl<<"ÇëÊäÈëÑ¹Õ»ÔªËØ£º"<<endl;
    }

}
