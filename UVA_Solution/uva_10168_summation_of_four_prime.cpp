#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
long long int status[10000000];
void siv()
{
    long long int N=10000000,i,j;
    long long int sq=sqrt(N);
    for( i=4; i<=N; i+=2) status[i]=1;
    for( i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=N; j+=i) status[j]=1;
        }
    }
    status[1]=1;

}
int main()
{
    long long int n,i,j,res,m;
    siv();
    while(scanf("%lld",&n)!=EOF)
    {
        if(n<8)
            printf("Impossible.\n");
        else
        {
            if(n%2==0)
            {
                printf("2 2 ");
                n=n-4;
            }
            else
            {
                printf("2 3 ");
                n=n-5;
            }
            m=n/2;
            for(i=2; i<=m; i++)
            {
                if(status[i]==0 && status[n-i]==0)
                {
                    printf("%lld %lld\n",i,n-i);
                    break;
                }
            }
        }
    }
    return 0;
}
