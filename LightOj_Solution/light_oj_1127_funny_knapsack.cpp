#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ara[32];
ll w;
int n, L,sz,sz2;
vector<ll>v,v2;
void go(int i,ll cnt,bool ck)
{
   ///cout<<"i = "<<i<<", cnt = "<<cnt<<endl;
    if(i==L){
        if(cnt<=w){
            if(ck){v.push_back(cnt);
            }
            else {v2.push_back(cnt);
            }
        }
        return;
    }
    go(i+1,cnt+ara[i],ck);
    go(i+1,cnt,ck);
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%d %lld",&n,&w);
        for(int i=0;i<n;i++)scanf("%lld",&ara[i]);
        L=n/2;
        go(0,0,true);
        L=n;
        ll ans=0;
        go(n/2,0,false);
        sort(v.begin(),v.end());
         sz=v.size();
         sz2=v2.size();
         ///cout<<"sz = "<<sz<<" ,sz2 = "<<sz2<<endl;
        for(int i=0;i<sz2;i++){
            ans+=(upper_bound(v.begin(),v.end(),w-v2[i])-v.begin());
        }
        printf("Case %d: %lld\n",a,ans);
        v.clear();v2.clear();
    }
    return 0;

}
