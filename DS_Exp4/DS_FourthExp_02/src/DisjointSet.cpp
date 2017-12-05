#include <iostream>
#include "DisjointSet.h"

DisjointSet::DisjointSet()
{
    num=0;
    Father=NULL;
}

DisjointSet::DisjointSet(int n)
{
    num=n;
    Father=new int[n+1];    //Useless 0. Due to address <=0
    for(int i=1;i<=num;i++)
    {
        Father[i]=0;
    }
}

DisjointSet::~DisjointSet()
{
    //dtor
}

int DisjointSet::Find(int x)
{
    if(Father[x]<=0)
    {
        return x;
    }
    int f=Find(Father[x]);
    Father[x]=f;
    return f;
}

void DisjointSet::Union(char xc,char yc)
{
    int x=GetNum(xc);
    int y=GetNum(yc);
    int fx=Find(x);
    int fy=Find(y);
    if(Father[fx]==Father[fy])
    {
        Father[fy]=fx;
        Father[fx]=Father[fx]-1;
    }else if(Father[fx]<Father[fy])
    {
        Father[fy]=fx;
    }else
    {
        Father[fx]=fy;
    }
}

int DisjointSet::GetNum(char c)
{
    return c-'A'+1;
}
