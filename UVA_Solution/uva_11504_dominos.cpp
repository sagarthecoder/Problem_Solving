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
vector<int>v[100002];
vector<int>taken;
stack<int>lst;
void dfs(int x)
{
    if(seen[x])return;
    seen[x]=true;
    for(int i=0;i<v[x].size();i++)
        dfs(v[x][i]);
    lst.push(x);
}
void dfs2(int x)
{
    if(seen[x])return;
    seen[x]=true;
    for(int i=0;i<v[x].size();i++)
        dfs2(v[x][i]);
}
int main()
{
    int t,n,m,res,a,b,cnt;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>n>>m;
        res=0,cnt=0;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            if(seen[a]==false){
                taken.push_back(a);
                seen[a]=true;
                cnt++;
            }
            if(seen[b]==false){
                taken.push_back(b);
                seen[b]=true;
                cnt++;
            }
        }
        seen.clear();
        for(int i=0;i<taken.size();i++)
        {
            a=taken[i];
            if(seen[a]==false)
            {
                dfs(a);
            }
        }
        seen.clear();
        while(!lst.empty())
        {
             a=lst.top();
            if(seen[a]==false)
            {
                dfs2(a);
                res++;
            }
            lst.pop();
        }
        cout<<res+n-cnt<<endl;
        seen.clear();
        taken.clear();
        for(int i=0;i<=n;i++)v[i].clear();
    }
    return 0;
}
