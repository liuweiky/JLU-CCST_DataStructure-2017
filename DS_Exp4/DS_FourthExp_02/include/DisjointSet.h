#ifndef DISJOINTSET_H
#define DISJOINTSET_H

class DisjointSet
{
    public:
        DisjointSet();
        DisjointSet(int n);
        int Find(int x);
        void Union(char x,char y);
        virtual ~DisjointSet();
        int* Father;
        int num;
        int GetNum(char c);
    protected:

    private:
};

#endif // DISJOINTSET_H
