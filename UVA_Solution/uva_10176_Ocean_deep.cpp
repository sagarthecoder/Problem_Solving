#include <bits/stdc++.h>
#define mod 131071
#define ll long long
using namespace std;
ll ara[10009];
ll bigmod ( ll a, ll p, ll m )
{
    //ok++;
    if ( p == 0 )return 1; // If power is 0 ( a ^ 0 ), return 1

    if ( p & 1 ) // If power is odd
    {
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m;
    }
    else
    {
       ll tmp = bigmod ( a, p / 2, m );
        return ( tmp * tmp ) % m;
    }
}
int main()
{
    string x;
    for(ll i=0;i<10002;i++)ara[i]=bigmod(2,i,mod);
    while(true)
    {
        getline(cin,x);
        if(x.empty())break;
        char ch;
        int len=x.size();
        //x.pop_back();
        if(x[len-1]!='#')
        {
            while(true)
            {
                cin>>ch;
                if(ch=='#')break;
                x+=ch;
            }
        }
         len=x.size();
         int ok=len;
        if(x[len-1]=='#')len--;

        ll ans=0;
        for(int i=len,j=0;i>=0;i--,j++)
        {
            if(x[i]=='1'){
               ans=((ans%mod)+(ara[j]%mod))%mod;
            }
        }
        if(ans==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        if(x[ok-1]!='#')getline(cin,x);
    }
    return 0;
}
