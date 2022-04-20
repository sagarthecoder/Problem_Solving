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
#include <unordered_map>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
map<string,vector<string> >v;
map<string,int>seen;
vector<string>taken;
int cnt=0;
void dfs(string x)
{
    if(seen[x])return;
    seen[x]=1;
    cnt++;
    for(int i=0;i<v[x].size();i++)
    {
        string y=v[x][i];
        dfs(y);
    }
}
int main()
{
    int c,r;
    while(true)
    {
        cin>>c>>r;
        string x,y;
        if(c==0 && r==0)break;
        int maxi=0;
        for(int i=0;i<c;i++){
            cin>>x;taken.emplace_back(x);
        }
        for(int i=0;i<r;i++){
            cin>>x>>y;
            v[x].emplace_back(y);
            v[y].emplace_back(x);
        }
        for(int i=0;i<c;i++)
        {
            x=taken[i];
            cnt=0;
            if(seen[x]==0)dfs(x);
            maxi=max(maxi,cnt);

        }
        v.clear();seen.clear();taken.clear();
        cout<<maxi<<endl;
       // cout<<endl;
    }
    return 0;
}
