#ifndef SSORT_H
#define SSORT_H


class SSort
{
    public:
        SSort(int n);
        virtual ~SSort();
        int num;
        int* NumberArray;
        long counter;
        void ShowArray();
        void Sort();
        void CheckCorrection();
        void ResetCounter();
        void WriteOut();
    protected:

    private:
};

#endif // SSORT_H
