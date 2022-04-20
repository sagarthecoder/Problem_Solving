#include <bits/stdc++.h>
#define ll long long
using namespace std;
int len=0;
bool H=0,O=0;
map<char,string>mp;

ll go1(ll a,ll n)
{
    if(n==0)return 1;
    if(n==1)return a;
    ll ans=go1(a,n/2);
    if(n%2==0)return ans*ans;
    else return ans*ans*a;

}

ll  go(string x)
{
    ll ans=0,b;
    if(H==0 && O==0)
    {
        for(int i=0;i<len;i++)
        ans=((10*ans)+(x[i]-'0'));
        ///cout<<"ans = "<<ans<<endl;
    }
    else
    {

       int k,j=0;
        if(H==1)
            k=2,b=16;
        else
            k=1,b=8;
            ll baranu=1;
        for(int i=len-1,j=0; i>=k; i--,j++)
        {
            if(j==0)baranu=1;
            else
            baranu*=b;
            if(x[i]!='0')
            {
                ll take;
                if(x[i]>='A' && x[i]<='F')take=10+(x[i]-'A');
                else take=x[i]-'0';
                if(x[i]!='0'){
                ans+=((take)*baranu);
                ///cout<<"gun = "<<take*baranu<<endl;

                }
            }
        }


        }

    return ans;


}
int main()
{
    string x;
    ll t;
    while(cin>>x)
    {
        H=0,O=0;
        cin>>t;
        if(x=="0" && t==0)break;
         len=x.size();
        if(x[0]=='0')
        {
            O=1;
        }
        if(len>1 && O==1)
        {
            if(x[1]=='x')
            {
                H=1;
            }
        }
        ll ck=go(x);
       /// cout<<"ck = "<<ck<<endl;
        string inc;
        int num,ans=0;

        for(int i=1;i<=t;i++)
        {
            cin>>inc>>num;
            if(inc=="++i")ck=ck+1;
            else if(inc=="--i")ck=ck-1;
            if(ck==num)ans++;
            ck=num;
            if(inc=="i++")ck=ck+1;
            else if(inc=="i--")ck=ck-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
