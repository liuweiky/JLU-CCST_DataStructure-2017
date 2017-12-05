#include <iostream>
#include <BinaryTree.h>

using namespace std;

void ShowMenu(int i);

int main()
{
    BinaryTree* BTree=new BinaryTree();

    ShowMenu(0);

    int operation=0;
    cin>>operation;

    while(operation)
    {
        char ch;
        Node* tmp;
        switch(operation)
        {
        case 1:
            ShowMenu(1);
            BTree->CreateTree();
            break;
        case 2:
            BTree->PreOrder(BTree->root);
            break;
        case 3:
            BTree->InOrder(BTree->root);
            break;
        case 4:
            BTree->PostOrder(BTree->root);
            break;
        case 5:
            ShowMenu(2);
            cin>>ch;
            tmp=BTree->GetFather(ch);
            if(tmp!=NULL)
            {
                cout<<"父节点是:"<<endl<<tmp->data<<endl;
            }else{
                cout<<"未找到!"<<endl;
            }
            break;
        case 6:
            ShowMenu(2);
            cin>>ch;
            tmp=BTree->Find(ch);
            if(tmp!=NULL)
            {
                cout<<"找到的是:"<<endl<<tmp->data<<endl;
            }else{
                cout<<"未找到!"<<endl;
            }
            break;
        case 7:
            /*if(BTree->IsComplete())
            {
                cout<<"完全二叉树!"<<endl;
            }else{
                cout<<"不是完全二叉树!"<<endl;
            }*/
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
        cout<<endl<<endl<<"请输入操作:";
        cout<<endl<<"1) 创建二叉树"<<endl<<"2) 先根遍历"<<endl<<"3) 中根遍历"<<endl<<"4) 后根遍历"<<endl<<"5）获取父节点"<<endl<<"6）搜索"<<endl/*<<"7）判断是否完全"<<endl*/<<"0) 退出"<<endl<<endl;
        break;
    case 1:
        cout<<endl<<"请输入树的先根序列:"<<endl;
        break;
    case 2:
        cout<<endl<<"请输入数据:"<<endl;
        break;
    }

}
