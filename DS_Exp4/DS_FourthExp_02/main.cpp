#include <iostream>
#include "DisjointSet.h"

using namespace std;

void ShowMenu(int i);

int main()
{
    DisjointSet* DSU;
    ShowMenu(0);

    int operation=0;
    cin>>operation;

    while(operation)
    {
        char x,y;
        switch(operation)
        {
        case 1:
            cout<<endl<<"请输入元素个数n"<<endl;
            cin>>operation;
            DSU=new DisjointSet(operation);
            break;
        case 2:
            cout<<endl<<"请输入等价关系 x y（1~n）"<<endl;
            cin>>x>>y;
            DSU->Union(x,y);
            break;
        case 3:
            cin>>x>>y;
            if(DSU->Find(DSU->GetNum(x))==DSU->Find(DSU->GetNum(y)))
            {
                cout<<"是"<<endl;
            }else
            {
                cout<<"否"<<endl;
            }
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
        cout<<endl<<"1) 创建并查集"<<endl<<"2) 构造等价类"<<endl<<"3）查询等价关系"<<endl<<"0）退出"<<endl;
        break;
    }
}
