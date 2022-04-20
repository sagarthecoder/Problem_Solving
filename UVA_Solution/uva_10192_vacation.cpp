#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int go(string x,string y,int len,int len2)
{
    for(int i=1;i<=len;i++)
    for(int j=1;j<=len2;j++){
        if(x[i-1]==y[j-1])dp[i][j]=1+dp[i-1][j-1];
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    return dp[len][len2];
}
int main()
{
    string x,y,z;
    int k=1;
    while(1)
    {
        getline(cin,x);
        if(x[0]=='#')break;
        getline(cin,y);
        //if(cin.eof())break;
        int res=go(x,y,x.size(),y.size());
        cout<<"Case #"<<k<<": you can visit at most "<<res<<" cities."<<endl;
        k++;
        //memset(dp,0,sizeof(dp));
    }
    return 0;
}

