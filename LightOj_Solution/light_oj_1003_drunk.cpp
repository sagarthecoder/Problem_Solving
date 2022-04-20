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
vector<string>lst;
map<string,int>seen;
int ck=0;
void dfs(string x)
{
    if(seen[x])return;
    seen[x]=true;
    for(int i=0;i<fst[x].size();i++)dfs(fst[x][i]);
    lst.push_back(x);
}
void dfs2(string x)
{
    if(seen[x])return;
    seen[x]=true;
    ck++;
    for(int i=0;i<rev[x].size();i++)dfs2(rev[x][i]);
    //lst.push_back(x);
}
int main()
{
    int t,m;
    string x,y,z;
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        cin>>m;
         bool what=true;
        bool rup=true;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            if(x==y)what=false;
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
        //seen.clear();
        if(what==false)
        {
            cout<<"Case "<<p<<": No"<<endl;
        }
        else{
        seen.clear();
        for(int i=0;i<taken.size();i++)
        {
            x=taken[i];
            if(seen[x]==false)
            {
                dfs(x);
            }
        }
        seen.clear();
        for(int i=lst.size()-1;i>=0;i--)
        {
            x=lst[i];
            ck=0;
            if(seen[x]==false)
            {

                dfs2(x);
            }
            if(ck>1)
            {
                cout<<"Case "<<p<<": No"<<endl;
                rup=false;
                break;
            }
        }
        if(rup==true)cout<<"Case "<<p<<": Yes"<<endl;
        }
        taken.clear();
        lst.clear();
        seen.clear();
        fst.clear();
        rev.clear();
        //cout<<ck<<endl;

    }
    return 0;
}

