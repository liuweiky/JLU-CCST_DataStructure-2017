#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        virtual ~Stack();
        void Push(char i);
        char Pop();
        char Peek();
        void Print();
        int GetTop();
        int top;
    protected:

    private:
        int size;
        char* StackArray;
};

#endif // STACK_H
