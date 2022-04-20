#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long int  dp[52][52];
long long int go(long long int n,long long r)
{
    if(r==1)return n;
    if(r==n || r==0)return 1;
    if(dp[n][r]!=0)return dp[n][r];
    else
    return dp[n][r]=go(n-1,r-1)+go(n-1,r);
}
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        string x;cin>>x;
        int len=x.size(),i,k,n;
        string y="",z="";
        for( i=1;i<=len;i++)
        {
            if(x[i]=='+')break;
            y+=x[i];
        }
        for(i=i+1;i<len;i++)
        {
            if(x[i]==')')break;
            z+=x[i];
        }
        for( i=i+2,k=1;i<len;i++,k++)
        {
            if(k==1)n=x[i]-'0';
            else n=(n*10)+(x[i]-'0');
        }
        cout<<"Case "<<a<<": ";
        ///cout<<y<<" "<<z<<" "<<n<<endl;
        for(ll i=0,j=n;i<=n;i++,j--)
        {
            ll ans=go(n,i);
            if(ans!=1)cout<<ans<<"*";
            if(j!=0){cout<<y;
            if(j!=1)cout<<"^"<<j;
            if(j!=n)cout<<"*";
            }
            if(i!=0){
                cout<<z;
                if(i!=1)cout<<"^"<<i;
            }
            if(i!=n)cout<<"+";
        }
        cout<<endl;
    }
    return 0;
}
