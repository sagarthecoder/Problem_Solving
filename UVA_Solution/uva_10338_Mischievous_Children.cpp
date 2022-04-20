#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
ll fact[22];
void go()
{
    fact[0]=1;
    for(ll i=1;i<=20;i++)fact[i]=i*fact[i-1];

}
int main()
{
    go();
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        string x;cin>>x;
        int len=x.size();
        int seen[100]={0};
        for(int i=0;i<len;i++)seen[x[i]]++;
        ll gun=fact[len];
        ll bhag=1;
        for(ll i='A';i<='Z';i++){
            if(seen[i]>1)bhag*=fact[seen[i]];
        }
        ll ans=gun/bhag;
        cout<<"Data set "<<a<<": "<<ans<<endl;
    }
    return 0;
}
