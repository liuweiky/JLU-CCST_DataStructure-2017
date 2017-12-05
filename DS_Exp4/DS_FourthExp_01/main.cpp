#include <iostream>
#include <Forest.h>
#include <Tree.h>

using namespace std;

/**ABE##CF#G#H##DI####*/

/*
ABE##CF#G#H##DI####
JK#F#G###
AB#C###
*/

void TreeOption();
void ForestOption();
void ShowMenu(int i);

int main()
{
    ShowMenu(0);

    int operation=0;
    cin>>operation;

    while(operation)
    {
        switch(operation)
        {
        case 1:
            TreeOption();
            break;
        case 2:
            ForestOption();
            break;
        }
        ShowMenu(0);
        cin>>operation;
    }

    return 0;
}

void TreeOption()
{
    ShowMenu(1);
    Tree* NormalTree=new Tree();
    int operation=0;
    cin>>operation;

    while(operation)
    {
        switch(operation)
        {
        case 1:
            ShowMenu(3);
            NormalTree->CreateTree();
            break;
        case 2:
            NormalTree->PreOrderR(NormalTree->root);
            break;
        case 3:
            NormalTree->PreOrderI();
            break;
        case 4:
            NormalTree->PostOrderR(NormalTree->root);
            break;
        case 5:
            NormalTree->PostOrderI();
            break;
        case 6:
            NormalTree->LevelOrder();
            break;
        }
        ShowMenu(1);
        cin>>operation;
    }
}

void ForestOption()
{
    ShowMenu(2);
    Forest* f;;
    int operation=0;
    cin>>operation;

    while(operation)
    {
        switch(operation)
        {
        case 1:
            ShowMenu(4);
            cin>>operation;
            f=new Forest(operation);
            break;
        case 2:
            f->PreOrderR(f->VirtualRoot);
            break;
        case 3:
            f->PreOrderI();
            break;
        case 4:
            f->PostOrderR(f->VirtualRoot);
            break;
        case 5:
            f->PostOrderI();
            break;
        case 6:
            f->LevelOrder();
            break;
        }
        ShowMenu(2);
        cin>>operation;
    }
}

void ShowMenu(int i)
{
    switch(i)
    {
    case 0:
        cout<<endl<<"1) 树操作"<<endl<<"2) 森林操作"<<endl<<"0）退出"<<endl;
        break;
    case 1:
        cout<<endl<<endl<<"请输入操作:";
        cout<<endl<<"1) 创建树"<<endl<<"2) 先根遍历（递归）"<<endl<<"3) 先根遍历（迭代）"<<endl<<"4) 后根遍历（递归）"<<endl<<"5）后根遍历（迭代）"<<endl<<"6）层次遍历"<<endl<<"0) 退出"<<endl<<endl;
        break;
    case 2:
        cout<<endl<<endl<<"请输入操作:";
        cout<<endl<<"1) 创建森林"<<endl<<"2) 先根遍历（递归）"<<endl<<"3) 先根遍历（迭代）"<<endl<<"4) 后根遍历（递归）"<<endl<<"5）后根遍历（迭代）"<<endl<<"6）层次遍历"<<endl<<"0) 退出"<<endl<<endl;
        break;
    case 3:
        cout<<endl<<"请输入树的先根序列:"<<endl;
        break;
    case 4:
        cout<<endl<<"请输入森林中树的数量/每棵树的先根序列:"<<endl;
        break;
    }

}
