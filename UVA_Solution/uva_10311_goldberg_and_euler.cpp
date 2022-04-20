#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
long long int  status[100000000];
void siv()
{
    long long int N=100000000,i,j;
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
        long long int m=n/2;
        ck=0;
        if(n<=4)
           printf("%lld is not the sum of two primes!\n",n);
        else if(n%2!=0 && status[n-2]==0)
            printf("%lld is the sum of 2 and %lld.\n",n,n-2);
        else if(n%2!=0 && status[n-2]!=0)
            printf("%lld is not the sum of two primes!\n",n);
        else{
        for(i=m; i>=2; i--)
        {
            if(status[i]==0 && status[n-i]==0 && i!=n-m )
            {

                ck=1;
                printf("%lld is the sum of %lld and %lld.\n",n,i,n-i);
                break;
            }
        }
        if(ck==0)
            printf("%lld is not the sum of two primes!\n",n);
        }
    }
    return 0;
}

