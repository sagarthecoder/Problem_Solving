#include <bits/stdc++.h>
#define ll long long
using namespace std;
int L[5003],par[5005],ck,mx=0,y;
bool seen[5006];
vector<int>v[5004];int bogging;
void dfs(int x,int cnt,int p)
{
    if(seen[x]==ck)return;seen[x]=ck;
    if(bogging==0)par[x]=p;
    L[x]=cnt;
    if(mx<cnt){
        mx=cnt;y=x;
    }
    for(int i=0;i<v[x].size();i++)dfs(v[x][i],cnt+1,x);
}
int main()
{
    int n,m,x;
    while(scanf("%d",&n)!=EOF)
    {
       ck=1;bogging=1,mx=0;
       set<int>ansMax,ansMin;
       set<int>::iterator it;
       for(int i=1;i<=n;i++)
       {
           scanf("%d",&m);
           while(m--)
           {
               scanf("%d",&x);
               v[i].push_back(x);
               v[x].push_back(i);
           }
       }
       dfs(1,0,0);
       bogging=0;
       for(int i=1;i<=n;i++)if(L[i]==mx){ansMax.insert(i);
       x=i;
       }
       mx=0,ck=0;dfs(y,0,0);int bap=y;int mid=mx/2;
       for(int i=1;i<=n;i++)if(L[i]==mx)ansMax.insert(i);
       ///if(mx%2!=0)mid--;
       for(int i=1;i<=mid;i++)
       {
           bap=par[bap];
       }
       ansMin.insert(bap);
       if(mx%2!=0)ansMin.insert(par[bap]);

       printf("Best Roots  : ");
       bool olala=false;
       for(it=ansMin.begin();it!=ansMin.end();++it){
         if(olala==true)printf(" ");olala=true;
         printf("%d",*it);
       }
       printf("\n");

       printf("Worst Roots : ");
        olala=false;
       for(it=ansMax.begin();it!=ansMax.end();++it){
         if(olala==true)printf(" ");olala=true;
         printf("%d",*it);
       }
       printf("\n");
       for(int i=1;i<=n;i++)
       {
           v[i].clear();seen[i]=0,L[i]=0,par[i]=0;
       }
    }
    return 0;
}
