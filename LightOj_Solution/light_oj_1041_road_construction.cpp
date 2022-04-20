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
#define ll long long
#define sf scanf
#define pf printf
#define pb push_back
using namespace std;
struct data
{
    string x,y;
    int len;
};
vector<data>v;
vector<string>input;
map<string,string>bap;
map<string,int>seen;
bool comp(data u,data u1)
{
    return u.len<u1.len;
}
string bapke(string x)
{
    if(bap[x]==x)return x;
    return bap[x]=bapke(bap[x]);
}
int main()
{
    int t,w,n;
    cin>>t;
    string x,y;
    for(int a=1;a<=t;a++)
    {
        data z;
        cin>>n;
        for(int i=0;i<n;i++){
        cin>>x>>y>>w;
        if(seen[
           x]==0){
            input.push_back(x);
            seen[x]=1;
        }
        if(seen[y]==0){
            input.push_back(y);seen[y]=1;
        }
         z.x=x,z.y=y,z.len=w;
        v.push_back(z);
        }
        sort(v.begin(),v.end(),comp);
        ///data z;
        int sz=input.size(),res=0,cnt=0;
        ///z.x=x,z.y=y,z.len=w;
       /// v.push_back(z);
        for(int i=0;i<sz;i++)bap[input[i]]=input[i];
        for(int i=0;i<n;i++)
        {
            string A=bapke(v[i].x);
            string B=bapke(v[i].y);
            if(A!=B){
                res+=v[i].len;
                cnt++;
                bap[B]=A;
                if(cnt==sz-1)break;
            }
        }
        cout<<"Case "<<a<<": ";
        if(cnt!=sz-1)cout<<"Impossible"<<endl;
        else
            cout<<res<<endl;
            v.clear();
            input.clear();
            bap.clear();
            seen.clear();

    }
    return 0;
}
