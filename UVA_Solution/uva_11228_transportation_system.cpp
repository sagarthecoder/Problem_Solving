#include <bits/stdc++.h>
using namespace std;
struct data
{
    int v1,v2;
    double w;
};
vector<data>v;
int bap[1004];
bool comp(data u,data u1)
{
    return u.w<u1.w;
}
int bapke(int x)
{
    if(bap[x]==x)return x;
    return bap[x]=bapke(bap[x]);
}
double dis(double x1,double y1,double x2,double y2)
{
    double ans;
    ans=sqrt(((x1-y1)*(x1-y1)) + ((x2-y2)*(x2-y2)));
    return ans;
}
int main()

{
    int t;cin>>t;
    for(int  a=1;a<=t;a++)
    {
        int n,r,cnt=0;cin>>n>>r;
        for(int i=0;i<=n;i++)bap[i]=i;
        int ara[n+1],ara2[n+1];
        double rail=0.0,road=0.0;
        for(int i=0;i<n;i++)cin>>ara[i]>>ara2[i];
        for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            double res=dis(ara[i],ara[j],ara2[i],ara2[j]);
            v.push_back({i+1,j+1,res});
        }
        sort(v.begin(),v.end(),comp);
        int sz=v.size();
        int state=0;
        for(int i=0;i<sz;i++)
        {
            int A=bapke(v[i].v1);
            int B=bapke(v[i].v2);
            if(A!=B)
            {
                bap[B]=A;
                ///cout<<"dis = "<<v[i].w<<endl;
                if(v[i].w<=r)road+=v[i].w;
                else{
                    rail+=v[i].w;
                    state++;
                }
                    cnt++;
                if(cnt==n-1)break;

            }
        }
        int ra=round(rail);
        int ro=round(road);
        cout<<"Case #"<<a<<": "<<state+1<<" "<<ro<<" "<<ra<<endl;
        ///cout<<setprecision (2) << fixed <<road<<" "<<rail<<endl;

        v.clear();

    }
    return 0;
}
