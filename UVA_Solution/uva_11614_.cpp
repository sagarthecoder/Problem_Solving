#include <cstdio>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
    long long int t,n;
    double x,y;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        x=sqrt(1+8*n);
        y=(x-1)/2.00;
        long long int  z=floor(y);
        printf("%lld\n",z);
    }
    return 0;
}
