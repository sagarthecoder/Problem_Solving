#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int x,y;
};
int n,m;
vector<data>v;
int dp[51][51][2600];
bool comp(data u,data u1)
{
    return u.y*u1.x>u.x*u1.y;
}
int go(int i,int cnt,int h)
{
    int ans=0;
    if(cnt==m)return 0;
    if(i==n)return -1000000000;
    if(dp[i][cnt][h]!=-1)return dp[i][cnt][h];
    //vis[i][cnt][h]=1;
    ans=max(ans,go(i+1,cnt+1,v[i].y+h)+(2*v[i].x*h)+(v[i].x*v[i].y));
    ans=max(ans,go(i+1,cnt,h));
    return dp[i][cnt][h]=ans;


}
int  main()
{
    int t,x,y;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%d %d",&n,&m);memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            v.push_back({x,y});
        }
        sort(v.begin(),v.end(),comp);
       /// cout<<endl;
        ///for(int i=0;i<n;i++)cout<<v[i].x<<" "<<v[i].y<<endl;
       int ans=go(0,0,0);
       printf("Case %d: %d\n",a,ans);
      // cout<<"ok = "<<ok<<endl;
       v.clear();
    }
    return 0;
}
