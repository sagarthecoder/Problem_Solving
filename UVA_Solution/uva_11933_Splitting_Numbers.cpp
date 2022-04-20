#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll go1(ll a,ll n)
{
    if(n==0)return 1;
    if(n==1)return a;
    ll ans=go1(a,n/2);
    if(n%2==0)return ans*ans;
    else return ans*ans*a;

}
int main()
{
    ll n;
    while(true)
    {
        scanf("%lld",&n);ll k=n;
        if(!n)break;
        vector<int>v,v1,v2;
        while(true)
        {
            int rem=n%2;
            v.push_back(rem);
            if(n/2==0)break;
            n=n/2;
        }
        int sz=v.size();ll A=0,B=0;
        bool ck=false;
        for(int i=0;i<sz;i++)
        {
            if(v[i]==1){
                if(ck==false){
                    v2.push_back(0);
                    v1.push_back(1);
                    ck=true;
                }
                else{
                    v2.push_back(1);
                    v1.push_back(0);
                    ck=false;
                }
            }
            else{
                v1.push_back(0);v2.push_back(0);
            }
        }
        for(int i=0;i<sz;i++){
            if(v1[i]==1){
                A+=go1(2,i);
            }
            if(v2[i]==1){
                B+=go1(2,i);
            }
        }
        printf("%lld %lld\n",A,B);

    }
    return 0;
}
