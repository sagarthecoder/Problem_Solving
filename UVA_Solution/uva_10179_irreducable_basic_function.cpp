#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long int n,taken,res,i,j;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;
        taken=n;
        if(n==1)
        {
            printf("1\n");
        }
        else
        {
            for(i=2; i*i<=n; i++)
            {
                if(n%i==0)
                {
                    while(n%i==0)
                    {
                        n=n/i;
                    }
                    taken=taken-(taken/i);
                }
            }

            if(n>1)
            {
                taken=taken-(taken/n);
            }
            printf("%lld\n",taken);
        }
    }
    return 0;
}
