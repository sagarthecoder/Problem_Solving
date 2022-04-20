#include <stdio.h>
long long int bigmod(long long int B,long long int P,long long int M)
{
    long long int res;
    if(P==0)
        return 1%M;
    res=bigmod(B,P/2,M);
    if(P%2==0)
    {
        return res=(res*res)%M;
    }
    else
    {
        return res=(res*res*B)%M;
    }
}
int main()
{
    long long int B,P,M,res1;
    while(scanf("%lld %lld %lld",&B,&P,&M)!=EOF)
    {
       res1= bigmod(B,P,M);
       printf("%lld\n",res1);
    }
    return 0;
}
