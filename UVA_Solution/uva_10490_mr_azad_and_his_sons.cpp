#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
long long int ara[40],status[32];
void siv()
{
    long long int N=32,i,j;
    ara[2]=1,ara[3]=1,ara[5]=1,ara[7]=1,ara[13]=1,ara[17]=1,ara[19]=1,ara[31]=1;

    int sq=sqrt(N);
    for(i=4; i<=N; i+=2) status[i]=1;
    for( i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for( j=i*i; j<=N; j+=i) status[j]=1;
        }
    }
    status[1]=1;

}
long long int multiple(long long int a)
{
    long long int i,res=1;
    for(i=1;i<=a;i++)
        res=res*2;
    return res;
}
int main()
{
    long long int n,i,j,res,sum1,sum2;
    siv();
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;
        if(ara[n]==1)
        {
            sum1=multiple(n-1);
            sum2=multiple(n)-1;
            res=sum1*sum2;
            printf("Perfect: %lld!\n",res);
        }
        else if(status[n]==0)
            printf("Given number is prime. But, NO perfect number is available.\n");
        else
            printf("Given number is NOT prime! NO perfect number is available.\n");
    }
    return 0;
}

