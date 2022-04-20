#include <bits/stdc++.h>
using namespace std;
struct data
{
    int v1,v2;
    double w;
};
vector<data>v;
int bap[102];
double dis(double x1,double y1,double x2,double y2)
{
    double ans;
    ans=sqrt(((x1-y1)*(x1-y1)) + ((x2-y2)*(x2-y2)));
    return ans;
}
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
    int t;
    cin>>t;
    for(int a=1;a<=t;a++)
    {
        int n;cin>>n;
        int k=0;
        double cnt=0.00;
        for(int i=0;i<=n;i++)bap[i]=i;
        double ara[n+1],ara2[n+1];
        for(int i=0;i<n;i++)cin>>ara[i]>>ara2[i];
        for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            double weight=dis(ara[i],ara[j],ara2[i],ara2[j]);
            v.push_back({i+1,j+1,weight});
        }
        sort(v.begin(),v.end(),comp);
        int sz=v.size();
        for(int i=0;i<sz;i++){
            int A=bapke(v[i].v1);
            int B=bapke(v[i].v2);
            if(A!=B){
                bap[B]=A;
                cnt+=v[i].w;
                k++;
                if(k==n-1)break;
            }
        }
        v.clear();
        cout << setprecision (2) << fixed <<cnt<<endl;
        if(a!=t)cout<<endl;
    }
    return 0;
}
