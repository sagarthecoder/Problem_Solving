#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<string>v;
int main()
{
    v.push_back("BCG");
    v.push_back("BGC");
    v.push_back("CBG");
    v.push_back("CGB");
    v.push_back("GBC");
    v.push_back("GCB");
    ll ara[12];
    /// B G C
    while(cin>>ara[1])
    {
        ll mini=1000000000000;
        for(int i=2;i<=9;i++)cin>>ara[i];
        string y="";
        for(int i=0;i<=5;i++)
        {
            string x=v[i];
            ll ck,ans=0;
            for(int j=0;j<3;j++){
                if(x[j]=='B')ck=1;
                else if(x[j]=='G')ck=2;
                else ck=3;
                for(ll k=1;k<=3;k++)
                {
                    if(ck!=k){
                        ans+=ara[(j*3)+k];
                        //cout<<"ok"<<endl;
                    }
                }

            }
            if(ans<mini){
                mini=ans;y=x;
            }
        }
        cout<<y<<" "<<mini<<endl;

    }
    return 0;
}
