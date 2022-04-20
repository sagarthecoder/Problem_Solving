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
#define ll long long
using namespace std;
struct data
{
    ll v1,v2;
    ll weight;
};
ll bapke[200005];
vector<data>v;
//vector<data>ans;
bool comp(data u,data v)
{
    return u.weight<v.weight;
}
ll bap(ll x)
{
    if(bapke[x]==x)return x;
    return bapke[x]=bap(bapke[x]);
}
int main()
{
   ll n,e;
   //freopen("uva.txt", "r", stdin);
   //freopen("output.txt", "w",stdout);
    while(true){
    ///freopen("uva.txt", "r", stdin);
   ///freopen("output.txt", "w",stdout);
   ///memset(bapke,0,sizeof(bapke));
   cin>>n>>e;
    int w,cnt=0,money=0,ans=0;
    if(n==0 && e==0)break;
    ll x,y;
    for(ll i=0;i<=n;i++)bapke[i]=i;
    for(ll i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        if(x<y)swap(x,y);
        v.push_back({x,y,w});
        money+=w;
    }
    sort(v.begin(),v.end(),comp);
    ///for(int i=0;i<e;i++)cout<<"We = "<<v[i].weight<<endl;
    for(ll i=0;i<e;i++){
        ll A=bap(v[i].v1);
        ll B=bap(v[i].v2);
        if(A!=B){bapke[B]=A;
        cnt+=v[i].weight;
        ans++;
        if(ans==n-1)break;
        }
    }
    ///cout<<"money = "<<money<<endl;
    cout<<money-cnt<<endl;

    v.clear();
    }
    return 0;


}
