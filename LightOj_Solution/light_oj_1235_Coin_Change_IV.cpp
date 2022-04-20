#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ara[40];
ll w;
int n, L,sz=0,sz2=0;
ll v[262150],v2[262150];
void go(int i,ll cnt,bool ck)
{
    ///cout<<"i = "<<i<<", cnt = "<<cnt<<endl;
    if(i==L)
    {
        if(cnt<=w)
        {
            if(ck==true)
            {
                v[sz]=cnt;
                sz++;
            }
            else
            {
                v2[sz2]=cnt;
                sz2++;
            }
        }
        return;
    }
    go(i+1,cnt+ara[i],ck);
    go(i+1,cnt+ara[i]+ara[i],ck);
    go(i+1,cnt,ck);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int a=1; a<=t; a++)
    {
        scanf("%d %lld",&n,&w);
        for(int i=0; i<n; i++)
            scanf("%lld",&ara[i]);
        L=n/2;
        sz=0,sz2=0;
        go(0,0,true);
        L=n;
        go(n/2,0,false);
        int ans;
        sort(v,v+sz);
        bool ck=false;
        ///cout<<"sz = "<<sz<<" ,sz2 = "<<sz2<<endl;
        for(int i=0; i<sz2; i++)
        {
            ans=(lower_bound(v,v+sz,w-v2[i])-v);
            if(v[ans]==w-v2[i])
            {
                ck=true;
                break;
            }
        }
        if(ck)
            printf("Case %d: Yes\n",a);
        else
            printf("Case %d: No\n",a);
    }
    return 0;

}
