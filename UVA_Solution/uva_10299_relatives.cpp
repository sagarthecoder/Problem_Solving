#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    long long int n,i,j,res;
    while(scanf("%lld",&n)!=EOF)
    {
        res=n;
        if(n==0)
            break;
        if(n==1)
            printf("0\n");
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
                    res=res-(res/i);

                }
            }
            if(n>1)
                res=res-(res/n);
            printf("%lld\n",res);
        }
    }
    return 0;
}

