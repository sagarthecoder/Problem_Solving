#include <bits/stdc++.h>
#define ll long long
#define diag 1
#define up 2
#define left 3
using namespace std;
ll dp[32][32][61];
ll rupsagar,len1,len2;
string x,y;
ll go(ll i,ll j,ll cnt)
{

    if(i==len1){
       if(cnt+len2-j==rupsagar)return 1;
       else return 0;
    }
     if(j==len2){
        if(cnt+len1-i==rupsagar)return 1;
        else return 0;
     }
     if(dp[i][j][cnt]!=-1)return dp[i][j][cnt];
     if(x[i]==y[j])return dp[i][j][cnt]=go(i+1,j+1,cnt+1);
     else return dp[i][j][cnt]=go(i+1,j,cnt+1)+go(i,j+1,cnt+1);
}
int main()
{
    ll t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {

        memset(dp,-1,sizeof(dp));
        cin>>x>>y;
         len1=x.size(),len2=y.size();

        ll table[len1+2][len2+2];
        for(int i=0; i<=len1; i++)
            for(int j=0; j<=len2; j++)
            {
                if(i==0 || j==0)
                    table[i][j]=0;
                else if(x[i-1]==y[j-1])
                {
                    table[i][j]=table[i-1][j-1]+1;
                }
                else
                {
                    table[i][j]=max(table[i-1][j],table[i][j-1]);
                }
            }
            ll sz=table[len1][len2];
             rupsagar=(len1+len2-sz);
            ll ans=go(0,0,0);
        cout<<"Case "<<a<<": "<<rupsagar<<" "<<ans<<endl;
    }
    return 0;

}
