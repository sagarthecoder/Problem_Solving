#include <bits/stdc++.h>
using namespace std;
struct data
{
    int n1,n2,w;
};
vector<data>v;
int main()
{
    int t;cin>>t;
    int n,m,x,y,w;
    for(int a=1;a<=t;a++)
    {
        cin>>n>>m;
        bool ck=false;
        int d[n];
        for(int i=0;i<n;i++)d[i]=1000000000;
        for(int i=0;i<m;i++){
            cin>>x>>y>>w;
            v.push_back({x,y,w});
        }
        d[0]=0;

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
           x=v[j].n1,y=v[j].n2,w=v[j].w;
           if(d[y]>d[x]+w)d[y]=d[x]+w;
        }
      for(int j=0;j<m;j++){
           x=v[j].n1,y=v[j].n2,w=v[j].w;
           if(d[y]>d[x]+w){
            ck=true;break;
           }
        }
        if(ck)cout<<"possible"<<endl; ///negative-cycle-ache
        else
            cout<<"not possible"<<endl;
        v.clear();
    }
    return 0;
}
