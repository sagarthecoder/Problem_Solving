#include <bits/stdc++.h>
using namespace std;
int seen[1000009],seen2[1000009];
vector<int>v[1000003];
bool status[1000009];
void siv()
{
    int N=1000001;
    int sq=sqrt(N);
    for(int i=4; i<=N; i+=2) status[i]=1;
    for(int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=N; j+=i) status[j]=1;
        }
    }
    status[1]=1;

}
void go(int P)
{
    int sq=sqrt(P);
    if(status[P]==1){
    while(true)
    {

        for( int cnt=2; cnt<=sq; cnt++)
        {
            if(P%cnt==0)
            {
                int A=P/cnt;


                    v[P].push_back(cnt);
                    v[cnt].push_back(P);
                if(A!=1)
                {
                    v[A].push_back(P);
                    v[P].push_back(A);
                }
            }
        }
        break;
    }
    }
}
void dfs(int x)
{
    if(seen[x])return;
    seen[x]=1;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i]);
}
int main()
{
    int t;
    scanf("%d",&t);
    siv();
    for(int a=1;a<=t; a++)
    {
        int n,one=0,cnt=0;
        scanf("%d",&n);
        int ara[n+2];
        memset(seen,0,sizeof(seen));
        memset(seen2,0,sizeof(seen2));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);
            if(ara[i]==1) one++;
        }
        for(int i=0;i<n;i++)
        {
            if(seen2[ara[i]]==0 && ara[i]!=1){
                go(ara[i]);
                seen2[ara[i]]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(seen[ara[i]]==0 && ara[i]!=1)
            {
                dfs(ara[i]);
                cnt++;
            }
        }
        printf("Case %d: %d\n",a,cnt+one);
        for(int i=0;i<n;i++)v[ara[i]].clear();


    }
    return 0;
}
