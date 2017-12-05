#include <iostream>
#include <SSort.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

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
        SSort* SS=new SSort(Number);
        cout<<"正在排序……"<<endl;
        SS->Sort();
        cout<<"正在校验正确性……"<<endl;
        SS->CheckCorrection();
        CTimes[i]=SS->counter;
        totalTime+=SS->counter;
        cout<<endl<<"比较次数: "<<SS->counter<<endl; //Comparison Time
        cout<<"正在保存数据……"<<endl;
        SS->WriteOut();
        delete SS;
        outfile<<"第"<<i+1<<"次运算比较次数: "<<CTimes[i]<<endl;
    }
    cout<<"////////////////////////////////////////////"<<endl<<endl;
    EndStamp=time(NULL);
    cout<<"运行时间(s): "<<EndStamp-BeginStamp<<endl;
    cout<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;
    outfile<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;
    return 0;
}
