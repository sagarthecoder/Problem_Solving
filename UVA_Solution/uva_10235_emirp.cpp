#include <cstdio>
#include <math.h>
#include <iostream>
#include <cstring>
using namespace std;
long long int  status[1000009];
void siv()
{
    long long int N=1000000;
    long long int sq=sqrt(N);
    for(long long int i=4; i<=N; i+=2) status[i]=1;
    for(long long int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(long long int j=i*i; j<=N; j+=i) status[j]=1;
        }
    }
    status[1]=1;

}
int main()
{
    long long int n,sum,taken;
    siv();
    while(scanf("%lld",&n)!=EOF)
    {
        sum=0;
        long long int rev=0,remainder;
        if(status[n]!=0)
        {
            printf("%lld is not prime.\n",n);
        }
        else
        {
            taken=n;
            if(taken>9)
            {
                while (taken > 0)
                {
                    remainder = taken % 10;
                    rev = rev * 10 + remainder;
                    taken /= 10;
                }
                if(status[rev]==0 && rev!=n)
                    printf("%lld is emirp.\n",n);
                else
                    printf("%lld is prime.\n",n);
            }
            else
            {
                printf("%lld is prime.\n",n);
            }
        }
    }
    return 0;
}
