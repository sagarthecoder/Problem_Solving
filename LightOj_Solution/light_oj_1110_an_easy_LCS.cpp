#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int a=1; a<=t; a++)
    {
        string x,y,z;
        cin>>x>>y;
        cout<<"Case "<<a<<": ";
        int len1=x.size(),len2=y.size();
        int dp[len1+2][len2+2],cnt=0;
        string s[len1+1][len2+1];
        for(int i=0; i<=len1; i++)
        {
            for(int j=0; j<=len2; j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0,s[i][j]="";
                else if(x[i-1]==y[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    s[i][j]=s[i-1][j-1]+x[i-1];
                }
                else if(dp[i-1][j]>dp[i][j-1])dp[i][j]=dp[i-1][j],s[i][j]=s[i-1][j];
                else if(dp[i-1][j]<dp[i][j-1])dp[i][j]=dp[i][j-1],s[i][j]=s[i][j-1];
                else dp[i][j]=dp[i][j-1],s[i][j]=min(s[i-1][j],s[i][j-1]);
            }
        }
        if(!dp[len1][len2])cout<<":("<<endl;
        else cout<<s[len1][len2]<<endl;
    }
    return 0;
}
