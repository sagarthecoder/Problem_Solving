#include <bits/stdc++.h>
#define ll long long
#define mx 1000000000
using namespace std;
struct data
{
    int xi,yi;
}ara[150];
int dp[310][310][45];
int dp2[310][310][45];
int go(int n,int i,int x,int y,int s,int cnt)
{
    int p,q,xx,yy,k=0;
    if(i==n)return 1000000000;
    ///cout<<"i,  x & y & cnt= "<<i<<" "<<x<<" "<<y<<" ,"<<cnt<<endl;
    //cout<<"start = "<<start<<endl;
    if(x<=300 && y<=300)
        if(dp[x][y][i]==mx)return dp[x][y][i];
    if(dp[x][y][i]!=-1)return cnt+dp2[x][y][i];
    //int res=(ara[i].xi*ara[i].xi)+(ara[i].yi+ara[i].yi);
     xx=x+ara[i].xi;
     yy=y+ara[i].yi;
    if(((xx*xx)+(yy*yy))==s){
            dp2[x][y][i]=0;
            return dp[x][y][i]= cnt;
    }
    if(((xx*xx)+(yy*yy))<=s)
    {
        p=go(n,i,xx,yy,s,cnt+1);
    }
    else p=1000000000;
     //cout<<"i,  x & y & cnt= "<<i<<" "<<x<<" "<<y<<" ,"<<cnt<<endl;

   // cout<<"p cnt  ="<<cnt<<endl;
    //if(ara[i]+start>s)return 1000000000;
    //int p=go(n,i,start+ara[i],s,cnt+1);
     q=go(n,i+1,x,y,s,cnt);
     ///cout<<"i,  x & y & cnt= "<<i<<" "<<x<<" "<<y<<" ,"<<cnt<<endl;
     //cout<<"q cnt = "<<cnt<<endl;
    //cout<<"min = "<<min(p,q)<<endl;;
    //cout<<"start = "<<x+y<<endl;
    //dp2[x][y][i]=cnt;
     dp[x][y][i]=min(p,q);
     if(dp[x][y][i]!=1000000000)
     dp2[x][y][i]=dp[x][y][i]-cnt;
     else dp2[x][y][i]=mx;
     ///cout<<"bacltrack = "<<"i,  x & y & cnt= "<<i<<" "<<x<<" "<<y<<" ,"<<cnt<<"  ,track = "<<dp2[x][y][i]<<endl;
     return dp[x][y][i];

}
int main()
{
    int t;cin>>t;;
    for(int a=1;a<=t;a++)
    {
        int m,s,x,y;
        memset(ara,0,sizeof(ara));
        memset(dp,-1,sizeof(dp));

        cin>>m>>s;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            ara[i].xi=x;
            ara[i].yi=y;

        }
        int ans=go(m,0,0,0,s*s,1);

        if(ans==1000000000)cout<<"not possible"<<endl;
        else
            cout<<ans<<endl;
       /// cout<<"my = "<<dp2[0][10][3]<<endl;

    }
    /*
    4 13
    0 1
    0 5
    0 2
    0 3
    */
    return 0;
}
