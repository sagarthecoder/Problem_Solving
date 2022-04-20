#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
bool status[1100002];
void siv()
{
    int N=1100000;
    int sq=sqrt(N);
    for(int i=4; i<=N; i+=2) status[i]=1;
    for(int i=3; i<=sq; i+=2)
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
    int n,i,j;
    siv();
    while(scanf("%d",&n))
    {
        if(n==0)break;
        int m=n/2;
        for(i=2; i<=m; i++)
        {
            if(status[i]==0 && status[n-i]==0)
            {
                printf("%d = %d + %d\n",n,i,n-i);
                break;
            }
        }
    }
    return 0;
}

