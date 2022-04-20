#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    ll x,y;
};
int seen[40005];
int main()
{
    int n,q;
    bool ck=false;
    while(true)
    {
        scanf("%d %d",&n,&q);
        ll R;
        data ara[n+2];
        memset(seen,0,sizeof(seen));
        if(!n && !q)break;
        ///if(ck==true)printf("\n");
        ck=true;
        for(int i=0;i<n;i++)scanf("%lld %lld",&ara[i].x,&ara[i].y);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ll dis=((ara[i].x-ara[j].x)*(ara[i].x-ara[j].x))+((ara[i].y-ara[j].y)*(ara[i].y-ara[j].y));
                double sq=sqrt((double)dis);
                ll flr=ceil(sq);
                seen[flr]++;
            }
        }
        for(int i=1;i<40001;i++)seen[i]+=(seen[i-1]);
        for(int i=1;i<=q;i++)
        {
            scanf("%lld",&R);
            double ans=(double)seen[R]/(double)n;
            printf("%.2f\n",ans);
        }
        printf("\n");

    }
    return 0;
}
