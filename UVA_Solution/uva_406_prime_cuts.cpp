#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
int nprime[1009];
vector<int>prime;
void sieve()
{
    //p=1;
    int x=1000;
    int i,j,k,sq;
    prime.push_back(1);
    prime.push_back(2);
    sq=sqrt(x)+1;
    for(i=4;i<=x;i+=2)
        nprime[i]=1;
    //prime[0]=2;
    for(i=3;i<=x;i+=2)
    {
        if(nprime[i]==0)
        {
            //prime[p]=i;
            prime.push_back(i);
            if(i<=sq)
            {
                for(j=i*i;j<=x;j+=i*2)
                    nprime[j]=1;
            }
            //p++;
        }
    }
}
int main()
{
    int n,c,i,j,taken,sum,res,ans;
    sieve();
    while(scanf("%d %d",&n,&c)!=EOF)
    {
        sum=0;
        for(i=0;i<prime.size();i++)
        {
            if(prime[i]>n)
            break;
            sum=sum+1;
        }
        if(sum%2==0)
            taken=(2*c);
        else
            taken=(2*c)-1;
        if(taken>sum)
        {
            printf("%d %d:",n,c);
            for(i=0;i<sum;i++)printf(" %d",prime[i]);
            printf("\n");
        }
        else
        {
            res=((sum)-taken)/2;
            printf("%d %d:",n,c);
            for(i=res;i<res+taken;i++)
            {
                printf(" %d",prime[i]);

            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
