#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long long int nprime[1000001],digit[1000001],mapping[1000001];
void sieve()
{
    long long int i,x,j,k,sq,take,sum,res=0;
    x=1000000;
    sq=sqrt(x)+1;
    for(i=4;i<=x;i+=2)
        nprime[i]=1;
        nprime[2]=0;
        digit[2]=1;
    for(i=3;i<=x;i+=2)
    {
        if(nprime[i]==0)
        {
            take=i,sum=0;
            while(1)
            {
                sum=sum+(take%10);
                take=take/10;
                if(take==0)
                {
                    if(nprime[sum]==0){
                        digit[i]=1;
                    }
                    break;
                }
            }
            if(i<=sq)
            {
                for(j=i*i;j<=x;j+=i*2)
                    nprime[j]=1;
            }
        }
    }
}
void ck()
{
    long long int sum=0,maxi=-1,i;
    for(i=0;i<=1000000;i++)
    {
        if(digit[i]==1)
        {
            sum=sum+1;
        }
        maxi=max(maxi,sum);
        mapping[i]=sum;
    }
}

int main()
{
    long long int n,i,t1,t2,res,taken;
    scanf("%lld",&n);
    sieve();
    ck();
    while(n--)
    {
        scanf("%lld %lld",&t1,&t2);
        if(t1>t2)
            swap(t1,t2);
            res=mapping[t2]-mapping[t1];
            if(digit[t1]==1)
                res=res+1;
            printf("%lld\n",res);

    }
    return 0;
}
