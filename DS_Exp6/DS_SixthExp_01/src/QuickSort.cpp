#include "QuickSort.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#define MAX_NUM 1000000
#define MIN_NUM 10

using namespace std;

QuickSort::QuickSort(int n)
{
    num=n;
    NumberArray=new int[num];

    for(int i=0;i<num;i++)
    {
        NumberArray[i]=((rand()*RAND_MAX+rand())%(MAX_NUM-MIN_NUM+1))+MIN_NUM;
    }
    WriteOut();
    counter=0;
}

QuickSort::~QuickSort()
{
    delete NumberArray;
}

void QuickSort::ShowArray()
{
    cout<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<NumberArray[i]<<' ';
    }
    cout<<endl;
}

void QuickSort::Sort(int* array,int m,int n)
{
    counter++;  ///Compensate Next If
    if(m<n)
    {
        int j=Partition(array,m,n);
        Sort(array,m,j-1);
        Sort(array,j+1,n);
    }
}

int QuickSort::Partition(int* array,int m,int n)
{
    int i=m,j=n+1;    /**j begin with n+1 to avoid only 2 elements situation*/
    while(i<j)
    {
        counter++;  ///Compensate Outer While
        /**No need to reassign i and j*/
        i++;    /**i++ to move on*/
        while(array[i]<array[m])
        {
            counter++;
            if(i==n)
            {
                i++;
                break;
            }
            i++;
        }
        counter++;  ///Compensate Last While
        j--;
        while(array[j]>array[m])
        {
            counter++;
            j--;
        }
        counter++;  ///Compensate Last While
        counter++;  ///Compensate Next If
        if(i<j)
        {
            int tmp=array[i];
            array[i]=array[j];
            array[j]=tmp;
        }
    }
    counter++;  ///Compensate Last While
    int tmp=array[m];
    array[m]=array[j];
    array[j]=tmp;;
    return j;
}

void QuickSort::CheckCorrection()
{
    bool isWrong=0;
    for(int i=0;i<num-1;i++)
    {
        if(NumberArray[i]>NumberArray[i+1])
        {
            cout<<endl<<"WRONG RESULT!"<<endl;
            cout<<"AT NUMBERARRAY["<<i<<']'<<endl;
            isWrong=1;
            //return;
        }
    }
    if(!isWrong)
    {
        cout<<endl<<"CORRECT RESULT!"<<endl;
    }
}

void QuickSort::ResetCounter()
{
    counter=0;
}

void QuickSort::WriteOut()
{
    ofstream os("sort.txt",ios::app);
    for(int i=0;i<num;i++)
    {
        os<<NumberArray[i]<<' ';
    }
    os<<endl<<endl;;
    os.close();
}
