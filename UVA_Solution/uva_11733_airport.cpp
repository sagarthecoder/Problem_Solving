#include <bits/stdc++.h>
using namespace std;
struct data
{
    int v1,v2,cost;
};
int bap[10005];
bool seen[10004];
vector<int>ans[10005];
//vector<data>v;
bool comp(data u,data u1)
{
    return u.cost<u1.cost;
}
int bapke(int x)
{
    if(bap[x]==x)return x;
    return bap[x]=bapke(bap[x]);
}
void dfs(int x)
{
    if(seen[x])return;
    seen[x]=true;
    for(int i=0;i<ans[x].size();i++)dfs(ans[x][i]);
}
int main()
{
    int t;
    cin>>t;
    for(int a=1;a<=t;a++)
    {
        int n,e,r,x,y,w,j=0,cnt=0;
        vector<data>v;
        //int ara[n+1];
        cin>>n>>e>>r;
        ///int ara[n+2];
        for(int i=0;i<=n;i++){bap[i]=i;
        seen[i]=false;
        }
        for(int i=0;i<e;i++){
            cin>>x>>y>>w;
            if(x<y)swap(x,y);
            v.push_back({x,y,w});
        }
        sort(v.begin(),v.end(),comp);
        int res=0;
        for(int i=0;i<e;i++){
            int A=bapke(v[i].v1);
            int B=bapke(v[i].v2);
            if(A!=B){

                bap[B]=A;
                if(v[i].cost>=r)res++;
                else
                cnt+=v[i].cost;
                ans[v[i].v1].push_back(v[i].v2);
                ans[v[i].v2].push_back(v[i].v1);
                /*if(seen[v[i].v1]==false){
                    ara[j++]=v[i].v1;
                    seen[v[i].v1]=true;
                }
                if(seen[v[i].v2]==false){
                    ara[j++]=v[i].v2;
                    seen[v[i].v2]=true;
                }*/
            }
        }
       // memset(seen,false,sizeof(seen));
        for(int i=1;i<=n;i++){
            if(seen[i]==0){
                dfs(i);res++;
            }
        }
        for(int i=0;i<=n;i++)ans[i].clear();
        cout<<"Case #"<<a<<": "<<cnt+(r*res)<<" "<<res<<endl;
    }
    return 0;
}
