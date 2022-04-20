#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
long long int  status[1000000];
void siv()
{
    long long int N=1000000,i,j;
    long long int sq=sqrt(N);
    for(i=4; i<=N; i+=2) status[i]=1;
    for(i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(j=i*i; j<=N; j+=i) status[j]=1;
        }
    }
    status[1]=1;
    status[0]=1;

}

int main()
{
    long long int n,i,j,ck;
    siv();
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;
        long long int m=n/2;
        ck=0;
        if(n<=3)
            printf("%lld:\nNO WAY!\n",n);
        else if(n%2!=0 && status[n-2]==0)
            printf("%lld:\n2+%lld\n",n,n-2);
        else if(n%2!=0 && status[n-2]!=0)
            printf("%lld:\nNO WAY!\n",n);
        else
        {

        for(i=2; i<=m; i++)
        {
            ck=1;
            if(status[i]==0 && status[n-i]==0)
            {
                printf("%lld:\n%lld+%lld\n",n,i,n-i);
                break;
            }
        }
            if(ck==0)
                printf("%lld:\nNO WAY!\n",n);
        }
    }
    return 0;
}

