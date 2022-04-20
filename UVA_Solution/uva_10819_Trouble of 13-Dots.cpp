#include <bits/stdc++.h>
#define mn INT_MIN
using namespace std;
int dp[14002][110],maxi=0;
bool ck;
int knapsack(int *ara,int *fav,int money,int n,int start,int i)
{
    int p,q,ok=0;
    if(i==n)
    {
        ///cout<<"startTTTTT!!! = "<<start<<endl;
        if(money<start && start<=2000){
                ////cout<<"return =  "<<start<<endl;
                return mn;
        }
        ///cout<<"start!!!!!! = "<<start<<endl;
        ///if(start>money && money<=2000)return 0;
       /// maxi=max(maxi,value);

        return 0 ;
    }
    /*if(start+ara[i]>2000 && money>1800  && ck==false){
        money+=200;
        ck=true;
    }*/
    if(dp[start][i]!=-1)return dp[start][i];
    ///if((start+ara[i]>2000 && start+ara[i]<=money+200))
       /// p=fav[i]+knapsack(ara,fav,money,n,start+ara[i],i+1);
     ///if(start+ara[i]<=money)/// || (start+ara[i]>2000 && start+ara[i]<=money+200))
     ///if(i==n && start>money && money<=2000) p=0;
      if(start+ara[i]>money && money<=1800)p=mn;
      if(start+ara[i]>money && money+200<start+ara[i])p=mn;
    /// else if(start+ara[i]>money && start+ara[i]<=2000)p=0;
     ///if(!((start+ara[i]>money && money<=1800)||(start+ara[i]>money && money+200<start+ara[i]) ||(start+ara[i]>money && start+ara[i]<=2000)))
    else
    {
        ///cout<<"st = "<<start+ara[i]<<endl;
       ///cout<<"fav = "<<fav[i]<<endl;
       ///cout<<endl;
        p=fav[i]+knapsack(ara,fav,money,n,start+ara[i],i+1);
    }

    ///else p=0;
    q=knapsack(ara,fav,money,n,start,i+1);
    ///if(start>money && money<=2000)p=0;
   // cout<<"start = "<<start<<endl;
    /// cout<<"p&q = "<<p<<" "<<q<<endl;
    //cout<<" i= "<<i<<endl;
    //cout<<"max ="<<max(p,q)<<endl<<endl;;
    ///cout<<
    ///cout<<"start = "<<start<<endl;
    ///cout<<"p = "<<p<<endl;
    return dp[start][i]=max(p,q);
}
int main()
{
    int n,k,money;
    while(scanf("%d %d",&money,&n)!=EOF)
    {
         int ara[n+1],fav[n+1],cnt=0;
        //ck=false;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){scanf("%d %d",&ara[i],&fav[i]);
        //cnt+=ara[i];
        }

        //if(cnt>2000 && money>1800)money+=200;
        printf("%d\n",knapsack(ara,fav,money,n,0,0));
       ///cout<<maxi<<endl;

    }
    return 0;
}
