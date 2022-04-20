#include <cstdio>
#include <iostream>
#define sagar scanf
#define rupa printf
using namespace std;

int main()
{
     long long int n,i,sum,num;
    while(sagar("%lld",&n)!=EOF)
    {
        if(n<0)
            break;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n=n/i;
                    rupa("    %lld\n",i);
                }
            }
        }
        if(n>1)
            rupa("    %lld\n",n);
        printf("\n");
    }
    return 0;
}
