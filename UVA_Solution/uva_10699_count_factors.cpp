#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long int n,i,sum,num,taken;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;
            sum=0;
            taken=n;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n=n/i;
                }
                sum=sum+1;

            }
        }
        if(n>1)
        {
            sum=sum+1;
        }
        printf("%lld : %lld\n",taken,sum);
    }
    return 0;
}
