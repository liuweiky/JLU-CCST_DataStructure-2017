#include <iostream>
#include <QuickSort.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <limits>

#define RUN_TIME 10

using namespace std;

int main()
{
    srand(time(0));
    int Number=0;
    cin>>Number;
    long* CTimes=new long[RUN_TIME];
    long long totalTime=0;
    ofstream outfile("stat.txt",ios::out);
    ofstream clear("sort.txt",ios::trunc);
    clear.close();
    ofstream os("sort.txt",ios::app);
    time_t EndStamp,BeginStamp=time(NULL);
    for(int i=0;i<RUN_TIME;i++)
    {
        //cin>>Number;
        cout<<"////////////////////////////////////////////";
        cout<<endl<<"第"<<i+1<<"次运算进行中……"<<endl;
        os<<"//////////////////////////"<<"第"<<i+1<<"次"<<"//////////////////////////"<<endl<<endl;
        cout<<"正在随机生成待排序元素……"<<endl;
        QuickSort* QS=new QuickSort(Number);
        cout<<"正在排序……"<<endl;
        QS->Sort(QS->NumberArray,0,QS->num-1);
        cout<<"正在校验正确性……"<<endl;
        QS->CheckCorrection();
        CTimes[i]=QS->counter;
        totalTime+=QS->counter;
        cout<<endl<<"比较次数: "<<QS->counter<<endl; //Comparison Time
        cout<<"正在保存数据……"<<endl;
        QS->WriteOut();
        delete QS;
        outfile<<"第"<<i+1<<"次运算比较次数: "<<CTimes[i]<<endl;
    }
    cout<<"////////////////////////////////////////////"<<endl<<endl;
    EndStamp=time(NULL);
    cout<<"运行时间(s): "<<EndStamp-BeginStamp<<endl;
    cout<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;
    outfile<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;

    return 0;
}
