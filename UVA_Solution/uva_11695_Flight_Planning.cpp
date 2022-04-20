#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int x,y;
};
vector<int>v[2505];
bool seen[2505],ck,omg;
int par[2502],par2[2505],ckx,cky,yUp,mx,mini,n;
void dfs(int x,int p)
{
    if(seen[x]==ck)return;seen[x]=ck;
    if(p!=0)
    par[x]=p;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i],x);
}
void dfs2(int x,int cnt,int p)
{
    if(seen[x]==ck)return;seen[x]=ck;
    if(mx<cnt){
        mx=cnt,yUp=x;
    }
    if(omg==1)par2[x]=p;
    for(int i=0;i<v[x].size();i++){
        if((v[x][i]==ckx && x==cky)||(v[x][i]==cky && x==ckx))continue;
        dfs2(v[x][i],cnt+1,x);
    }
}

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int x,y,cutX,cutY,joinX,joinY;scanf("%d",&n);mx=0;///memset(bap,-1,sizeof(bap));
        vector<data>take;
        for(int i=0;i<n-1;i++){
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
            take.push_back({x,y});
        }
        ck=1;
        dfs(1,0);ck=0,mini=300000;
        for(int i=0;i<n-1;i++)
        {
            omg=0;///cout<<endl;
            ckx=take[i].x,cky=take[i].y;mx=-1,ck=0;int cntx=0,cnty=0;
            dfs2(ckx,0,0);///cout<<"before 1st mx = "<<mx<<endl;
            mx=-1;
            omg=1;int newChildX1=yUp;ck=1;
            dfs2(yUp,0,0);cntx=mx;int newChildX2=yUp;///cout<<"mx1st = "<<mx<<endl;
           /// for(int k=1;k<=cntx;k++)newChildX2=
           int log=0;mx=mx/2;
           ///cout<<"newx1 = "<<newChildX2<<endl;
           for(int k=1;k<=mx;k++)newChildX2=par2[newChildX2];
           ///cout<<"newx1 after = "<<newChildX2<<endl;
            ck=0,mx=-1,omg=0,log=0;
            dfs2(cky,0,0);/*cout<<"before 2nd mx = "<<mx<<endl;*/mx=-1,ck=1;
            omg=1;int newChildY1=yUp;
            dfs2(yUp,0,0);cnty=mx;int newChildY2=yUp;///cout<<"mx2nd = "<<mx<<endl;
            mx=mx/2;///cout<<"newy1 = "<<newChildY1<<endl;
            for(int k=1;k<=mx;k++)newChildY2=par2[newChildY2];
            ///cout<<"newy1 after = "<<newChildY2<<endl;
            int sum=max(cntx,cnty);
            sum =max(sum,(cntx/2) + (cnty/2) + (cntx%2) + (cnty%2) +1);
            ///cout<<"sum  = "<<sum<<endl;
            if(sum<mini){
                mini=sum;cutX=ckx,cutY=cky;
                joinX=newChildX2,joinY=newChildY2;



            }

        }
        printf("%d\n",mini);
        printf("%d %d\n",cutX,cutY);
        printf("%d %d\n",joinX,joinY);
        for(int i=0;i<=n;i++){
            v[i].clear();seen[i]=0,par[i]=0,par2[i]=0;
        }

    }
    return 0;
}
