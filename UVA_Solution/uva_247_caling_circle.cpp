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
map<string,vector<string> >fst;
map<string,vector<string> >rev;
vector<string>taken;
stack<string>lst;
map<string,int>seen;
bool ck;
void dfs(string x)
{
    if(seen[x])return;
    seen[x]=true;
    for(int i=0;i<fst[x].size();i++)dfs(fst[x][i]);
    lst.push(x);
}
void dfs2(string x)
{
    if(seen[x])return;
    if(ck==true)cout<<", ";
    ck=true;
    cout<<x;
    seen[x]=true;
    for(int i=0;i<rev[x].size();i++)dfs2(rev[x][i]);
}
int main()
{
    int n,m,cnt=1;
    while(true)
    {
        cin>>n>>m;
        string x,y;
        if(n==0 && m==0)break;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            fst[x].push_back(y);
            rev[y].push_back(x);
            if(seen[x]==false){
                taken.push_back(x);
                seen[x]=true;
            }
            if(seen[y]==false){
                taken.push_back(y);
                seen[y]=true;
            }
        }
        cout<<"Calling circles for data set "<<cnt<<":"<<endl;
        seen.clear();
        for(int i=0;i<taken.size();i++){
            x=taken[i];
            if(seen[x]==false){
                dfs(x);
            }
        }
        seen.clear();
        while(!lst.empty())
        {
            x=lst.top();
            ck=false;
            if(seen[x]==false){
                dfs2(x);
                cout<<endl;
            }
            lst.pop();
        }
        //cout<<endl;
        seen.clear();
        taken.clear();
        fst.clear();
        rev.clear();
        cnt++;
    }
    return 0;
}

