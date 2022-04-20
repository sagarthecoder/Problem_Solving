#include <cstdio>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
    long long int t,L,U,sq,cnt,i,j,maxi,res,take;
    scanf("%lld",&t);
    while(t--)
    {
        maxi=-1;
        scanf("%lld %lld",&L,&U);
        for(i=L;i<=U;i++)
        {
            cnt=0;
            sq=sqrt(i);
            for(j=1;j<=sq;j++)
            {
                if(i%j==0)
                {
                    cnt=cnt+1;
                }
            }
            if(sq==sqrt(i))
            {
                res=(cnt*2)-1;
            }
            else
            {
                res=cnt*2;
            }
            if(res>maxi)
            {
                maxi=res;
                take=i;

            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",L,U,take,maxi);
    }
    return 0;
}
