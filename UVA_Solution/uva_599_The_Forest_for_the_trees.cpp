#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>v[28];
int cnt=0;
bool seen[27];
void dfs(int x)
{
    if(seen[x])return;seen[x]=1;
    cnt++;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i]);
}
int main()
{
    int t;cin>>t;
    string x;
    while(t--)
    {
        while(true){
        cin>>x;
        if(x[0]=='*')break;
        v[x[1]-'A'].push_back(x[3]-'A');
        v[x[3]-'A'].push_back(x[1]-'A');
        }
        int tree=0,acorn=0;
        cin>>x;int len=x.size();
        for(int i=0;i<len;i++)
        {
            if(x[i]>='A' && x[i]<='Z'){
                if(!seen[x[i]-'A']){
                    cnt=0;dfs(x[i]-'A');
                    if(cnt>1)tree++;
                    else acorn++;
                }
            }

        }
        cout<<"There are "<<tree<<" tree(s) and "<<acorn<<" acorn(s)."<<endl;
        for(int i=0;i<=26;i++){
            seen[i]=0;v[i].clear();
        }

    }
    return 0;
}
