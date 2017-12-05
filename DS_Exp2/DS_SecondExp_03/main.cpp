#include <iostream>
#include <List.h>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    /*int j;
    List* StrList=new List();
    cout<<""<<endl;
    cin>>j;
    for(int i=0;i<j;i++)
    {
        char c;
        cin>>c;
        StrList->Insert(c);
    }
    if(StrList->Check()==-1)
    {
        cout<<"true";
    }else
    {
        cout<<StrList->Check();
    }*/

    char S1[100];
    char S2[100];
    char S3[100];
    cout<<"S1,S2,S3:"<<endl;
    cin.getline(S1,20);
    cin.getline(S2,20);
    cin.getline(S3,20);
    //cin>>S1>>S2>>S3;
    cout<<endl;
    cout<<"S1: "<<S1<<endl<<"S2: "<<S2<<endl<<"S3: "<<S3<<endl;
    //cout<<strlen(S1)<<endl;

    //bool flag=false;

    int pos=-1;

    for(int i=0;i<=strlen(S1)-strlen(S2);i++)
    {
        int j;
        if(S1[i]==S2[0])
        {
            for(j=0;j<strlen(S2);j++)
            {
                if(S1[i+j]!=S2[j])
                {
                    break;
                }
            }
            if(j==strlen(S2))
            {
                pos=i;
                //cout<<"S1"<<S1<<endl<<"S2"<<S2<<endl<<"S3"<<S3<<endl;
                if(strlen(S3)>=strlen(S2))
                {
                    for(int k=strlen(S1);k>=pos+strlen(S2);k--)
                    {
                        //cout<<endl<<"S1"<<S1<<endl<<"S2"<<S2<<endl<<"S3"<<S3<<endl;
                        S1[k+strlen(S3)-strlen(S2)]=S1[k];
                    }
                }else
                {
                    for(int k=pos+strlen(S3);k<=strlen(S1);k++)
                    {
                        S1[k]=S1[k+strlen(S2)-strlen(S3)];
                    }
                }
                for(int k=0;k<strlen(S3);k++)
                {
                    S1[pos+k]=S3[k];
                }
            }
        }
    }

    //cout<<pos;

    if(pos==-1)
    {
        for(int i=0;i<strlen(S3);i++)
        {
            S1[strlen(S1)-1-i]=S3[i];
        }
    }else
    {
        /*//cout<<"S1"<<S1<<endl<<"S2"<<S2<<endl<<"S3"<<S3<<endl;
        for(int i=strlen(S1);i>=pos+strlen(S2);i--)
        {
            //cout<<endl<<"S1"<<S1<<endl<<"S2"<<S2<<endl<<"S3"<<S3<<endl;
            S1[i+strlen(S3)-strlen(S2)]=S1[i];
        }
        for(int i=0;i<strlen(S3);i++)
        {
            S1[pos+i]=S3[i];
        }*/
    }

    cout<<endl<<"S1: "<<S1<<endl;

    return 0;
}
