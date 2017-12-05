#include <iostream>
#include <Queue.h>

using namespace std;
void ShowMenu(int i);

int main()
{
    Queue* queue=new Queue();

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
            queue->Insert(in);
            break;
        case 2:
            queue->Delete();
            break;
        case 3:
            if(queue->front!=NULL)
            cout<<endl<<'['<<queue->Front()<<']'<<endl;
            break;
        case 4:
            queue->Print();
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
        cout<<endl<<"请输入操作：";
        cout<<endl<<"1) 插入队尾"<<endl<<"2) 删除队首"<<endl<<"3) 读取队首"<<endl<<"4) 显示队列"<<endl<<"0) 退出"<<endl<<endl;
        break;
    case 1:
        cout<<endl<<"请输入入队元素："<<endl;
    }

}
