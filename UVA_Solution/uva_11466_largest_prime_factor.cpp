#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long int n,i,sum,num,taken,res;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;
        res=0;
        if(n<0)
        {
            n=-n;
        }
        if(n<5)
            printf("-1\n");
        else
        {
            for(i=2; i*i<=n; i++)
            {
                if(n%i==0)
                {
                    res=res+1;
                    while(n%i==0)
                    {
                        n=n/i;
                        sum=i;
                    }
                }
            }
            if(n>1)
            {
                sum=n;
                res=res+1;
            }
            if(res==1)
                printf("-1\n");
            else
                printf("%lld\n",sum);

        }
    }
    return 0;
}
