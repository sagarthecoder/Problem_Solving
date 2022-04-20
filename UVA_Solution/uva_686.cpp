#include <cstdio>
#include <math.h>
#include <cstring>
#include <iostream>
using namespace std;
bool status[40009];
void siv()
{
    int N=32800;
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
    int n,i,res;
    siv();
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        int ara[32790],res=0;
        memset(ara,0,sizeof(ara));
        int m=n/2;
        for(i=2;i<=m;i++)
        {
            if(status[i]==0 && status[n-i]==0 && ((ara[i]==0 || ara[n-i]==0)))
            {
                res=res+1;
                ara[i]=1;
                ara[n-i]=1;

            }
        }
        printf("%d\n",res);


    }
    return 0;
}
