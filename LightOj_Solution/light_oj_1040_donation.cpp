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
    int v1,v2,w;
};
vector<data>v;
int bap[52];
bool comp(data u,data u1)
{
    return u.w<u1.w;
}
int bapke(int x)
{
    if(bap[x]==x)return x;
    return bap[x]=bapke(bap[x]);
}
int main()
{
    int t,n,x,y,len;
    sf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        sf("%d",&n);
        for(int i=0;i<=n;i++)bap[i]=i;
        int total=0,cnt=0,weight=0;
        data z;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                sf("%d",&len);
                total+=len;
                ///cout<<"tot = "<<total<<endl;
                z.v1=i,z.v2=j,z.w=len;
                if(len!=0)v.pb(z);
            }
        }
        int sz=v.size();
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<sz;i++){
            int A=bapke(v[i].v1);
            int B=bapke(v[i].v2);
            if(A!=B){
              weight+=v[i].w;
              ///cout<<"inside weight = "<<weight<<endl;
              cnt++;
              bap[B]=A;
              if(cnt==n-1)break;
            }
        }
        ///cout<<"weight = "<<weight<<endl;
        pf("Case %d: ",a);
        if(cnt<n-1)pf("-1\n");
        else
            pf("%d\n",total-weight);
        v.clear();

    }
    return 0;
}
