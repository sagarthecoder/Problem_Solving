#include <bits/stdc++.h>
using namespace std;
bool status[1000006];
int ans[1000004];
   vector<int>prime;
void siv(){
    status[1]=1;
    status[0]=1;
    int M=1000000;
     for(int i=2;i<=M;i++){
        if(status[i]==false){
            prime.push_back(i);
            for(int j=2*i;j<=M;j=j+i){
                status[j]=true;
            }
        }
    }
}
void go()
{
    int N=1000000;
    for(int i=2;i<=N;i++)
    {
        int take=i,cnt=0;
        for(int j=0;prime[j]*prime[j]<=take;j++)
        {
            if(take%prime[j]==0)
            {
                while(take%prime[j]==0)
                {
                    cnt++;
                    take=take/prime[j];
                }
            }
        }
        if(take>1)cnt++;
        ans[i]=ans[i-1]+cnt;

    }
}
int main()
{
    int n;
    siv();
    go();
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",ans[n]);
    }
    return 0;
}
