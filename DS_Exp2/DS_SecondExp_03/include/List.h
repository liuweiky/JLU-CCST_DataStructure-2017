#ifndef LIST_H
#define LIST_H

class Node
{
public:
    Node* Next;
    char data;
    Node(){Next=NULL;data=' ';}
    Node(char i){Next=NULL;data=i;}
};


class List
{
    public:
        List();
        virtual ~List();
        void Insert(char ch);
        int Check();
    protected:

    private:
        Node* head;
        Node* tail;
};

#endif // LIST_H
