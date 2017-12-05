#ifndef QUICKSORT_H
#define QUICKSORT_H

class QuickSort
{
    public:
        QuickSort(int n);
        QuickSort(int n,int w);
        virtual ~QuickSort();
        int num;
        int* NumberArray;
        long long counter;
        long long count0;
        void ShowArray();
        void Sort(int* array,int m,int n);
        void CheckCorrection();
        void ResetCounter();
        void WriteOut();
    protected:

    private:
        int Partition(int* array,int m,int n);
};

#endif // QUICKSORT_H
