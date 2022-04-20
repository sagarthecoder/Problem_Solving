#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int x,y,z,t;
    float avg,m,n,res;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&x,&y,&z);
        avg=(x+y)/3.0;
        m=x-avg;
        n=y-avg;
        if(x<=avg)
        {
            printf("0\n");
        }
        else if(y<=avg)
        {
            printf("%d\n",z);
        }
        else
        {
            res=((z)/(m+n))*m;
            printf("%.0f\n",res);
        }
    }
    return 0;
}
