
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        string x;cin>>x;
        int len=x.size();
        ll ara[len+2];memset(ara,0,sizeof(ara));
        for(ll i=1;i<=8;i++)
        {
            cin>>x;
            for(ll j=1;j<len-1;j++)
            {
                ll ogo=0;
                if(x[j]=='\\')ogo=1;
                if(ogo)ara[j]+=(1ll<<(i-1));
            }
        }
        cin>>x;
        for(ll i=1;i<len-1;i++){
            cout<<(char)ara[i];
        }
        cout<<endl;
    }
    return 0;
}
