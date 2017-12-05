#ifndef QUICKSORT_H
#define QUICKSORT_H

class QuickSort
{
    public:
        QuickSort(int n);
        virtual ~QuickSort();
        int num;
        int* NumberArray;
        long counter;
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
