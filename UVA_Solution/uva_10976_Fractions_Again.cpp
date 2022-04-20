#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    ll x,y;
};
int main()
{
    ll k;
    while(scanf("%lld",&k)!=EOF)
    {
        ll L=k+1,R=k+k;
        vector<data>v;
        for(ll i=L;i<=R;i++)
        {
            double bhag=(double)(-k*i)/(double)(k-i);
            ll cel=ceil(bhag),flr=floor(bhag);
            if(cel==flr){
                if(cel>=i)v.push_back({cel,i});
                else v.push_back({i,cel});
            }
        }
        int sz=v.size();
        printf("%d\n",sz);
        for(int i=0;i<sz;i++)
        {
            printf("1/%lld = 1/%lld + 1/%lld\n",k,v[i].x,v[i].y);
        }
    }
    return 0;
}
