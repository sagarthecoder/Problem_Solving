#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>v[5004];
int L[5004],par[5004],bap[5004][13];
bool seen[5004];
void dfs(int x,int p,int level)
{
    if(seen[x])return;seen[x]=1;
    L[x]=level,par[x]=p;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i],x,level+1);

}
void LisCnt(int n)
{
    memset(bap,-1,sizeof(bap));
    for(int i=1;i<=n;i++)bap[i][0]=par[i];

    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j<=n;j++)bap[j][i]=bap[bap[j][i-1]][i-1];
}
int go(int n,int p,int q)
{
    if(L[p]<L[q])swap(p,q);
    int log=0;
    if(L[p]!=0)log=log2(L[p]);

    for(int i=log;i>=0;i--){
        if(L[p]-(1<<i)>=L[q])p=bap[p][i];
    }
    if(p==q)return p;
    for(int i=log;i>=0;i--)
    {
        if(bap[p][i]!=-1 && bap[p][i]!=bap[q][i])p=bap[p][i],q=bap[q][i];

    }
    return par[p];
}
int main()
{
    int n;
    while(true)
    {
        scanf("%d",&n);
        int x,y,q;
        if(!n)break;
        for(int i=0;i<n-1;i++){
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,1,0);
        ///for(int i=1;i<=n;i++)cout<<"level of "<<i<<" = "<<L[i]<<endl;
        LisCnt(n);
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            scanf("%d %d",&x,&y);
            int ans=go(n,x,y);
            ///cout<<"LCA = "<<ans<<endl;
            ///cout<<"Len = "<<abs(L[ans]-L[x])<<endl;
            int  L2,start;
            int x1=L[x]-L[ans];
            int y1=L[y]-L[ans];
            if(x1==y1)printf("The fleas meet at %d.\n",ans);
            else ///if(abs(x1-y1)%2==0)
            {

               /// cout<<"inside = "<<endl;
                if(L[x]>=L[y])start=x,L2=x1-((x1+y1)/2)+L[ans];
                else start=y,L2=y1-((x1+y1)/2)+L[ans];
               /// cout<<"start = "<<start<<",  ans L2= "<<L2<<endl;
                int log=0;
                if(L[start]!=0)log=log2(L[start]);
                for(int i=log;i>=0;i--)
                {
                    if(L[start]-(1<<i)>=L2)start=bap[start][i];
                }

                if(abs(x1-y1)%2==0)printf("The fleas meet at %d.\n",start);
                else
                {
                  int a=min(start,par[start]),b=max(start,par[start]);
                  printf("The fleas jump forever between %d and %d.\n",a,b);
                }
                 ///if(x1==x2)printf("The fleas meet at %d.\n",start);
            }
            /*else
            {
                int L2,start;
                if(L[x]>=L[y])start=x,L2=L[x1]
            }*/
        }
        memset(seen,0,sizeof(seen));
        for(int i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}
