#include <bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<string,ll>seen;
vector<string>v;
int main()
{
    ll t;cin>>t;
    string x;
    getline(cin,x);
    getline(cin,x);
    for(int a=1;a<=t;a++)
    {
        int cnt=0;
        while(true)
        {
            getline(cin,x);
            ll len=x.size();if(len==0)break;
            if(seen[x]==0)v.push_back(x);
            seen[x]++;
            cnt++;
        }
        sort(v.begin(),v.end());
        ll sz=v.size();
        for(int i=0;i<sz;i++)
        {
            cout<<v[i]<<" ";
            double bhag=(100*seen[v[i]]*1.0)/cnt;
            cout << setprecision (4) << fixed <<bhag<<endl;
        }
        if(a!=t)cout<<endl;
        seen.clear();
        v.clear();
    }
    return 0;
}
