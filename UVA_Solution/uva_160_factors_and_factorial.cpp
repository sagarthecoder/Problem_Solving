#include <cstdio>
#include <math.h>
#include <iostream>
#include <cstring>
using namespace std;
bool status[118];
void siv()
{
    int N=110;
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
    int n,i,j,total,taken,line;
    siv();
    while(scanf("%d",&n)!=EOF){
    if(n==0)
        break;
        line=1;
        if(n<10)
            printf("  ");
        else if(n<100)
            printf(" ");
    printf("%d! =",n);
    for(i=2;i<=n;i++)
    {
        if(status[i]==0)
        {
            taken=i;
            total=0;
            while(taken<=n)
            {
                total=total+(n/taken);
                taken=i*taken;
            }
            if(line==16)
            {
                printf("\n");
                printf("      ");

                line=1;
            }
            if(total<10)
                printf("  ");
            else
                printf(" ");
            printf("%d",total);
            line=line+1;

        }
    }
    printf("\n");
    }
    return 0;
}
