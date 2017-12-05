#ifndef SSORT_H
#define SSORT_H


class SSort
{
    public:
        SSort(int n);
        SSort(int n,int w);
        virtual ~SSort();
        int num;
        int* NumberArray;
        long long counter;
        long long count0;
        void ShowArray();
        void Sort();
        void CheckCorrection();
        void ResetCounter();
        void WriteOut();
    protected:

    private:
};

#endif // SSORT_H
