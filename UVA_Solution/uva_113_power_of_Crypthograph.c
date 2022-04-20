#include <stdio.h>
#include <math.h>
int main()
{
    double x,y;
    while(scanf("%lf %lf",&x,&y)!=EOF)
    {
       double ans=pow(y,1/x);
       printf("%0.lf\n",ans);
    }
    return 0;
}
