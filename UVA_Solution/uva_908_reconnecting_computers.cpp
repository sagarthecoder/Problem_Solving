#include <bits/stdc++.h>
using namespace std;
struct data
{
    int v1,v2,w1;
};
vector<data>v;
int bap[1000004];
bool comp(data u,data u1)
{
    return u.w1<u1.w1;
}
int bapke(int x)
{
    if(bap[x]==x)return x;
    return bap[x]=bapke(bap[x]);
}
int main()
{
    int n;
    bool ck=false;
    while(cin>>n)
    {
        int res1=0,x,y,w,k,m,cnt=0,accha=0;
        if(ck==true)cout<<endl;
        ck=true;
        for(int i=0;i<=n;i++)bap[i]=i;
        for(int i=0;i<n-1;i++){
            cin>>x>>y>>w;
            res1+=w;
        }
        cin>>k;
        for(int i=0;i<k;i++){
            cin>>x>>y>>w;
            if(x<y)swap(x,y);
            v.push_back({x,y,w});
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>x>>y>>w;
            if(x<y)swap(x,y);
            v.push_back({x,y,w});
        }
        sort(v.begin(),v.end(),comp);
        ///int sz=v.size();
        ///cout<<"sz= "<<sz<<endl;
        for(int i=0;i<k+m;i++){
            int A=bapke(v[i].v1);
            int B=bapke(v[i].v2);
            if(A!=B){
                bap[B]=A;
                accha+=v[i].w1;
                cnt++;
                if(cnt==n-1)break;
            }
        }
        cout<<res1<<endl<<accha<<endl;
        v.clear();
    }
    return 0;
}
