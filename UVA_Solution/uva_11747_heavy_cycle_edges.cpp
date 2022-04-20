#include <bits/stdc++.h>
using namespace std;
struct data
{
    int v1,v2,w1;
};
vector<data>v;
int bap[1007];
bool comp(data u,data u1)
{
    return u.w1<u1.w1;
}
int bapke(int x)
{
    if(bap[x]==x)return x;
    return bap[x]=bapke(bap[x]);
}
void mst(int n,int e)
{
    //int bap[n+2];
    vector<int>ans;
    int sum=0;
    for(int i=0;i<=n;i++)bap[i]=i;
    for(int i=0;i<e;i++)
    {
        int c1=v[i].v1;
        int c2=v[i].v2;
        int A=bapke(c1);
        int B=bapke(c2);
        if(A==B){
            //c1=v[i].w;
            ans.push_back(v[i].w1);
        }
        else
            bap[B]=A;
    }
    int sz=ans.size();
    bool ck=false;
    if(sz==0)cout<<"forest"<<endl;
    else
    {
        for(int i=0;i<sz;i++){
            if(ck==true)cout<<" ";
            cout<<ans[i];
            ck=true;
        }
        cout<<endl;
    }
}
int main()
{
    int n,e;
    while(cin>>n>>e)
    {
        if(n==0 && e==0)break;
        int x,y,w;
        for(int i=0;i<e;i++){
            cin>>x>>y>>w;
            if(x<y)swap(x,y);
            v.push_back({x,y,w});
        }
        sort(v.begin(),v.end(),comp);
        mst(n,e);
        v.clear();
    }
    return 0;
}
