#include <bits/stdc++.h>
using namespace std;
struct data
{
    string x;
    int low,high,pos;
};
vector<data>v;
int g;
bool comp(data u,data u1)
{
    if(u.low==u1.low && u.high==u1.high)return u.pos<u1.pos;
    if(u.low==u1.low)return u.high<u1.high;
    return u.low<u1.low;
}
int main()
{
    int t;
    cin>>t;
    for(int a=1;a<=t;a++)
    {
        int d;
        cin>>d;
        string x;
        int L,H;
        for(int i=0; i<d; i++)
        {
            cin>>x>>L>>H;
            v.push_back({x,L,H,i});
        }
        sort(v.begin(),v.end(),comp);
        int q,n;
        cin>>q;
        for(int i=0; i<q; i++)
        {
            cin>>n;
            int cnt=0;
            g=-1;
            for(int j=0;j<d;j++){
               if (n<= v[j].high && v[j].low<=n){cnt++;
                g=j;
                if(cnt>1)break;
               }
               if(v[j].low>n)break;

            }
            if(cnt!=1)cout<<"UNDETERMINED"<<endl;
            else cout<<v[g].x<<endl;


        }
        v.clear();
        if(a!=t)cout<<endl;
    }

    return 0;
}
