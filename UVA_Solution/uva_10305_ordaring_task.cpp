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
vector<int>v[110];
stack<int>s;
map<int,int>seen;
void dfs(int x)
{
    if(seen[x])return;
    seen[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int top=v[x][i];
        dfs(top);
    }
    s.push(x);
}
int main()
{
    int n,m,x,y;
    while(true){
    cin>>n>>m;
    if(n==0 && m==0)break;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        if(seen[i]==0)
            dfs(i);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    seen.clear();
    for(int i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}
