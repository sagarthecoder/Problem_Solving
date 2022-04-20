#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>v[102];
bool ans[103], seen[102];
int dis[102],low[102],one=0,t=0,par[103];
void dfs(int x)
{
    t++;
    ///cout<<"Node = "<<x<<endl;
    dis[x]=t,low[x]=t;
    seen[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==par[x])continue;
        if(seen[v[x][i]]){
            low[x]=min(low[x],dis[v[x][i]]);
        }
        else
        {
            if(x==1)one++;
            if(one>1)ans[1]=1;
            par[v[x][i]]=x;
            dfs(v[x][i]);
            low[x]=min(low[x],low[v[x][i]]);
            if(dis[x]<=low[v[x][i]] && x!=1)ans[x]=true;
        }
    }
}
int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if(!n)break;
        string x;
        one=0,t=0;
        getline(cin,x);
        while(true)
        {
            getline(cin,x);
            if(x=="0")break;
            int i=0,s=0,len=x.size();
            for(;i<len;i++){
                if(x[i]==' ')break;
                ///cout<<"char = "<<x[i]<<endl;
                s=(s*10)+(x[i]-'0');
            }
            int y=0;
           /// cout<<"source = "<<s<<endl;
            for(int j=i+1;j<len;j++)
            {
               /// cout<<"x[j ] = "<<x[j]<<endl;
                if(x[j]==' '){
                    if(y!=0){
                        ///cout<<" y "<<y<<endl;
                        v[s].push_back(y);
                        v[y].push_back(s);
                    }
                    y=0;
                }
                else y=(y*10)+(x[j]-'0');
            }
            if(y!=0){
                v[s].push_back(y);
                v[y].push_back(s);
            }

        }
       /// cout<<"source size = "<<v[5].size()<<endl;
        dfs(1);
        int sagar=0;
        for(int i=1;i<=n;i++)if(ans[i])sagar++;
        for(int i=0;i<=n;i++){
            v[i].clear();ans[i]=0,par[i]=0,low[i]=0;
            seen[i]=0,dis[i]=0;
        }
        cout<<sagar<<endl;

    }
    return 0;
}
