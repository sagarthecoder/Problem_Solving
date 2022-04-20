#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int ara[500009];
int again[500009];
int bapke(int n)
{
    if(ara[n]==n)
        return n;
    else
        bapke(ara[n]);
}
int main()
{
    int n,m,i,A,B,t,maxi;
    scanf("%d",&t);
    while(t--){
    scanf("%d %d",&n,&m);
    maxi=-1;
    for(i=0;i<=n;i++)
    {
        ara[i]=i;
        again[i]=0;
    }
    for(i=1;i<=m;i++)
    {
       scanf("%d %d",&A,&B);
       if(A>B)
        swap(A,B);
       A=bapke(A);
       B=bapke(B);
       if(A!=B)
       {
          ara[B]=A;
       }


    }
    for(i=1;i<=n;i++)
    {
        int x=bapke(i);
        again[x]=again[x]+1;
        if(maxi<again[x])
        {
            maxi=again[x];
        }
    }
    printf("%d\n",maxi);
    }
    return 0;

}
