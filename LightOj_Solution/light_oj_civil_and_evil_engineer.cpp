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
int bap[102];
vector<data>v;
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
    int t,n;
    sf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        sf("%d",&n);
        for(int i=0;i<=n;i++)bap[i]=i;
        int one=0,two=0;
        int x,y,c,e=0;
        data z;
        while(true)
        {
            sf("%d %d %d",&x,&y,&c);
            if(x==0 && y==0 && c==0)break;
            e++;
            z.v1=x,z.v2=y,z.w=c;
            v.pb(z);
        }
        sort(v.begin(),v.end(),comp);
        int cnt=0;
        for(int i=0;i<e;i++)
        {
            int A=bapke(v[i].v1);
            int B=bapke(v[i].v2);
            if(A!=B){
                bap[B]=A;
                one+=v[i].w;
                cnt++;
                if(cnt==n)break;
            }
        }
        for(int i=0;i<=n;i++)bap[i]=i;
        cnt=0;
         for(int i=e-1;i>=0;i--)
        {
            int A=bapke(v[i].v1);
            int B=bapke(v[i].v2);
            if(A!=B){
                bap[B]=A;
                two+=v[i].w;
                cnt++;
                if(cnt==n)break;
            }
        }
        pf("Case %d: ",a);
        if((one+two)%2==0)pf("%d\n",(one+two)/2);
        else
            pf("%d/2\n",one+two);
        v.clear();
    }
    return 0;
}
