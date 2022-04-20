#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    long long int n,i,sum;
    while(scanf("%lld",&n)!=EOF)
    {
        sum=0;
        if(n==0)
            break;
        for(i=1;i<=n;i++)
        {
            sum=sum+(i*i);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
