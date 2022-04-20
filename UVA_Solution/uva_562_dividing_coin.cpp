#include<cstdio>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include <unordered_map>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
///int dp[100][25002];
int dp[105][50005];
///unordered_map<int,unordered_map<int,int> >dp;
int go(int *ara,int cap,int m,int s,int i)
{
    int p,q;
    if(i==m)return 0;
    if(dp[i][cap]!=0)return dp[i][cap];
    if(cap+ara[i]<=s)p=ara[i]+go(ara,cap+ara[i],m,s,i+1);
    else p=0;
    q=go(ara,cap,m,s,i+1);
    return dp[i][cap]=max(p,q);
}
int main()
{
    int t,m;
    //freeopen("stdin",input.in);
    cin>>t;
    for(int a=1;a<=t;a++)
    {
        cin>>m;
        memset(dp,0,sizeof(dp));
        int cnt=0,s;
        int ara[m+1];
       /// int dp[m+1][501];
        for(int i=0;i<m;i++)
        {
           cin>>ara[i];
           cnt+=ara[i];
        }
        if(cnt==1)cout<<1;//<<endl;
        else{
        //double x=(cnt*1.00)/2.0;
        ///s=ceil(x);
        s=cnt/2;
        ///cout<<"cnt ="<<cnt<<endl;
        ///cout<<"s ="<<s<<endl;
        int res=go(ara,0,m,s,0);
        ///cout<<"res = "<<res<<endl;
        /*if(cnt-s==res)cout<<0<<endl;
        else*/
            cout<<abs((cnt-res)-res);//<<endl;
            ///dp.clear();
        }
        cout<<endl;
        //if(a!=t)cout<<endl;

    }
    return 0;
}
