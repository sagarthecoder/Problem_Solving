#include<cstdio>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define ll long long int
map<int,int>seen;
vector<int>taken;
vector<int>fst[1000];
vector<int>rev[1000];
stack<int>lst;
void dfs(int x)
{
    if(seen[x])return;
    seen[x]=true;
    for(int i=0; i<fst[x].size(); i++)dfs(fst[x][i]);
    lst.push(x);
}
void dfs2(int x)
{
    if(seen[x])return;
    seen[x]=true;
    for(int i=0; i<rev[x].size(); i++)dfs2(rev[x][i]);
}
int main()
{
    int n,m,x,y,p,cnt;
    while(true)
    {
        cin>>n>>m;
        int sec=0;
        cnt=0;
        if(n==0 && m==0)break;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y>>p;
            fst[x].push_back(y);
            rev[y].push_back(x);
            if(p==2)
            {
                fst[y].push_back(x);
                rev[x].push_back(y);
            }
            if(seen[x]==false)
            {
                taken.push_back(x);
                seen[x]=true;
                sec++;
            }
            if(seen[y]==false)
            {
                taken.push_back(y);
                seen[y]=true;
                sec++;
            }
        }
        seen.clear();
        for(int i=0; i<taken.size(); i++)
        {
            x=taken[i];
            if(seen[x]==false)
            {
                dfs(x);
                seen[x]=true;
            }
        }
        seen.clear();
        while(!lst.empty())
        {
            x=lst.top();
            if(seen[x]==false)
            {
                dfs2(x);
                cnt++;
                //if(cnt==2)break;
            }
            lst.pop();
        }
        if(cnt+n-sec>=2)cout<<0<<endl;
        else
            cout<<1<<endl;
            seen.clear();
            taken.clear();
            for(int i=0;i<=n;i++)
            {
                fst[i].clear();
                rev[i].clear();
                //lst.clear();
            }
    }
    return 0;
}
