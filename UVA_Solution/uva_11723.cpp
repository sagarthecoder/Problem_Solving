#include <cstdio>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
    int t=1,r,n;
    while(scanf("%d %d",&r,&n)!=EOF)
    {
        float v=r-n;
        if(r==0 && n==0)
            break;
        if(r<n)
        {
            printf("Case %d: 0\n",t++);
        }
        else if(v/n>26)
        {
            printf("Case %d: impossible\n",t++);
        }
        else if(v/n<v)
        {
            int q=ceil(v/n);
            printf("Case %d: %d\n",t++,q);
        }
        else
        {
            printf("Case %d: %d\n",t++,v/n);
        }
    }
    return 0;
}
