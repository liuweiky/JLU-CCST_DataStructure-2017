#include <iostream>
#include <SSort.h>
#include <QuickSort.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#define RUN_TIME 10

using namespace std;

int main()
{
    srand(time(0));
    long* CTimes=new long[RUN_TIME];
    long long totalTime=0;
    ofstream clearStat("stat.txt",ios::trunc);
    clearStat.close();
    ofstream outfile("stat.txt",ios::app);
    ofstream outfileQ("statQ.txt",ios::out);
    ofstream outfileS("statS.txt",ios::out);
    ofstream clearQ("sortQ.txt",ios::trunc);
    clearQ.close();
    ofstream clearS("sortS.txt",ios::trunc);
    clearS.close();
    ofstream osQ("sortQ.txt",ios::app);
    ofstream osS("sortS.txt",ios::app);
    cout<<"请输入N-快速排序"<<endl<<endl;
    int Number=0;
    cin>>Number;
    outfile<<endl<<"//////////////////////////"<<"快速排序"<<"//////////////////////////"<<endl<<endl;
    for(int i=0;i<RUN_TIME;i++)
    {
        //cin>>Number;
        cout<<"////////////////////////////////////////////";
        cout<<endl<<"第"<<i+1<<"次运算进行中……"<<endl;
        osQ<<"//////////////////////////"<<"第"<<i+1<<"次"<<"//////////////////////////"<<endl<<endl;
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
        outfileQ<<"第"<<i+1<<"次运算比较次数: "<<CTimes[i]<<endl;
        outfile<<"第"<<i+1<<"次运算比较次数: "<<CTimes[i]<<endl;
    }
    cout<<"////////////////////////////////////////////"<<endl<<endl;
    //cout<<"运行时间(s): "<<EndStamp-BeginStamp<<endl;
    //cout<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;
    outfileQ<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;
    outfile<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;
    outfileQ.close();

    cout<<"请输入N-选择排序"<<endl<<endl;
    totalTime=0;
    cin>>Number;
    outfile<<endl<<"//////////////////////////"<<"选择排序"<<"//////////////////////////"<<endl<<endl;
    for(int i=0;i<RUN_TIME;i++)
    {
        cout<<"////////////////////////////////////////////";
        cout<<endl<<"第"<<i+1<<"次运算进行中……"<<endl;
        osS<<"//////////////////////////"<<"第"<<i+1<<"次"<<"//////////////////////////"<<endl<<endl;
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
        outfileS<<"第"<<i+1<<"次运算比较次数: "<<CTimes[i]<<endl;
        outfile<<"第"<<i+1<<"次运算比较次数: "<<CTimes[i]<<endl;
    }
    cout<<"////////////////////////////////////////////"<<endl<<endl;
    //cout<<"运行时间(s): "<<EndStamp-BeginStamp<<endl;
    //cout<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;
    outfileS<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;
    outfile<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;
    outfileS.close();

    outfile.close();

    clock_t startTime,endTime;
    cout<<"请输入N-快速排序（大数据）"<<endl<<endl;
    cin>>Number;
    int sum[10][2];
    for(int i=0;i<10;i++)
        for(int j=0;j<2;j++)
            sum[i][j]=0;
    startTime=clock();
    for(int i=0;i<RUN_TIME;i++)
    {
        clock_t start,end;
        start=clock();
        //cout<<"////////////////////////////////////////////";
        //cout<<endl<<"第"<<i+1<<"次运算进行中……"<<endl;
        //cout<<"正在随机生成待排序元素……"<<endl;
        QuickSort* QS=new QuickSort(Number,0);
        //cout<<"正在排序……"<<endl;
        QS->Sort(QS->NumberArray,0,QS->num-1);
        CTimes[i]=QS->counter;
        totalTime+=QS->counter;
        delete QS;
        end=clock();
        sum[i][0]=start;
        sum[i][1]=end;
        //cout<<"单次时间："<<(double)(end-start)/CLOCKS_PER_SEC<<'s'<<endl;
    }
    endTime=clock();
    cout<<endl<<"起始时刻："<<(double)startTime<<endl<<"终止时刻："<<endTime<<endl<<"总计时间："<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<'s'
        <<endl<<"平均时间："<<(double)(endTime-startTime)/(CLOCKS_PER_SEC*RUN_TIME)<<'s'<<endl;

    for(int i=0;i<10;i++)
    {
        cout<<"第"<<i+1<<"次运行时间: "<<(double)(sum[i][1]-sum[i][0])/CLOCKS_PER_SEC<<endl;
    }

    for(int i=0;i<10;i++)
    {
        cout<<"第"<<i+1<<"次运算比较次数: "<<CTimes[i]<<endl;
    }

    cout<<"总计比较次数: "<<(long long)totalTime<<endl<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;

    cout<<endl<<"请输入N-选择排序（大数据）"<<endl<<endl;
    cin>>Number;
    startTime=clock();
    for(int i=0;i<RUN_TIME;i++)
    {
        clock_t start,end;
        start=clock();
        //cout<<"////////////////////////////////////////////";
        //cout<<endl<<"第"<<i+1<<"次运算进行中……"<<endl;
        //cout<<"正在随机生成待排序元素……"<<endl;
        SSort* SS=new SSort(Number,0);
        //cout<<"正在排序……"<<endl;
        SS->Sort();
        CTimes[i]=SS->counter;
        totalTime+=SS->counter;
        delete SS;
        end=clock();
        sum[i][0]=start;
        sum[i][1]=end;
        //cout<<"单次时间："<<(double)(end-start)/CLOCKS_PER_SEC<<'s'<<endl;
    }
    endTime=clock();
    cout<<endl<<"起始时刻："<<(double)startTime<<endl<<"终止时刻："<<endTime<<endl<<"总计时间："<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<'s'
        <<endl<<"平均时间："<<(double)(endTime-startTime)/(CLOCKS_PER_SEC*RUN_TIME)<<'s'<<endl;

    for(int i=0;i<10;i++)
    {
        cout<<"第"<<i+1<<"次运行时间: "<<(double)(sum[i][1]-sum[i][0])/CLOCKS_PER_SEC<<endl;
    }

    for(int i=0;i<10;i++)
    {
        cout<<"第"<<i+1<<"次运算比较次数: "<<CTimes[i]<<endl;
    }

    cout<<"总计比较次数: "<<(long long)totalTime<<endl<<"平均比较次数: "<<(long long)totalTime/RUN_TIME<<endl;
    return 0;
}
