#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int t1=1;t1<=t;t1++)
    {
        int a,b;
        char y[2];
        scanf("%d",&a);
        scanf("%s",y);
        scanf("%d",&b);
        double r=(double)sqrt((a*a)+(b*b))/(double)2;
        double theta=acos((double)((r*r)+(r*r)-(b*b))/(2*r*r));
        double s=r*theta;
        double x=400/(double)((2*s)+(2*a));
        double a1=a*x,b1=b*x;
        printf("Case %d: %.10f %.10f\n",t1,a1,b1);

    }
    return 0;
}
