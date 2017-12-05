#include "SSort.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#define MAX_NUM 1000000
#define MIN_NUM 10

using namespace std;

SSort::SSort(int n)
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

SSort::SSort(int n,int w)
{
    num=n;
    NumberArray=new int[num];

    for(int i=0;i<num;i++)
    {
        NumberArray[i]=((rand()*RAND_MAX+rand())%(MAX_NUM-MIN_NUM+1))+MIN_NUM;
    }
    counter=0;
}

SSort::~SSort()
{
    delete NumberArray;
}

void SSort::ShowArray()
{
    cout<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<NumberArray[i]<<' ';
    }
    cout<<endl;
}

void SSort::Sort()
{
    for(int i=0;i<num-1;i++)
    {
        int min=i;
        for(int j=i+1;j<num;j++)
        {
            counter++;
            //cout<<counter<<endl;
            if(NumberArray[j]<NumberArray[min])
            {
                min=j;
            }
        }
        int tmp=NumberArray[min];
        NumberArray[min]=NumberArray[i];
        NumberArray[i]=tmp;
    }
}

void SSort::CheckCorrection()
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

void SSort::ResetCounter()
{
    counter=0;
}

void SSort::WriteOut()
{
    ofstream os("sortS.txt",ios::app);
    for(int i=0;i<num;i++)
    {
        os<<NumberArray[i]<<' ';
    }
    os<<endl<<endl;
    os.close();
}
