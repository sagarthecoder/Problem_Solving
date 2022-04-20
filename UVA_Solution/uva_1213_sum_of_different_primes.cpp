#include <bits/stdc++.h>
using namespace std;
int prime[250],p=0,ans=0;
bool status[1160];
int dp[2000][21][252];
void go()
{
    status[1]=1;
    status[0]=1;
     for(int i=2;i<=1150;i++){
        if(status[i]==false){
            prime[p++]=i;
            for(int j=2*i;j<=1150;j=j+i){
                status[j]=true;
            }
        }
    }
}
int knapsack(int n,int k,int cnt,int start,int pm)
{


        if(start-prime[pm]<0 || cnt>k)return 0;
        if(dp[start][cnt][pm]!=-1){
                //if(cnt==k)return 1;
                //cout<<"subproblems start,cnt,pm = "<<start<<" "<<cnt<<" "<<pm<<endl;
                return dp[start][cnt][pm];
        }
        //if(start-prime[pm]<0 || cnt>k)return 0;
        if(start-prime[pm]==0 && cnt==k){
            return 1;
            //return;
        }
        //ok++;
        ///cout<<"val = "<<start+prime[pm]<<endl;
        ///cout<<"cnt = "<<cnt<<endl;
        ///cout<<endl;
    return dp[start][cnt][pm]= knapsack(n,k,cnt+1,start-prime[pm],pm+1)+knapsack(n,k,cnt,start,pm+1);
    //int d=knapsack(n,k,cnt,start,pm+1);
    //cout<<"c ="<<c<<endl;
    //printf("start =%d ,pm=%d ,cnt=%d \n\n",start,pm,cnt);
    //return dp[start][cnt][pm]=c;
}
int main()
{
    go();
    while(true)
    {
        int n,k;scanf("%d %d",&n,&k);
        //memset(dp,-1,sizeof(dp));
        if(n==0 && k==0)break;
        memset(dp,-1,sizeof(dp));
        //printf("%d\n",knapsack(n,k,1,0,0));
        printf("%d\n",knapsack(0,k,1,n,0));
        //cout<<ans<<endl;
        //cout<<"ok= "<<ok<<endl;
    }
    return 0;
}
