#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        virtual ~Stack();
        void Push(int i);
        int Pop();
        int Peek();
        void Print();
        int top;
    protected:

    private:
        int size;
        int* StackArray;
};

#endif // STACK_H
