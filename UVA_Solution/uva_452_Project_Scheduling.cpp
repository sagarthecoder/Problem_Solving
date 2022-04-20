#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cost[30],ind[30];
bool seen[30];
vector<int>v[30];
int mx=0,tot[30];
void dfs(int x,int sum)
{
    if(tot[x]>=sum)return;
    ///cout<<"x = "<<x<<" sum = "<<sum<<endl;
    tot[x]=sum;mx=max(mx,sum);
    for(int i=0;i<v[x].size();i++)dfs(v[x][i],sum+cost[v[x][i]]);
}
int main()
{
    int t;
    scanf("%d",&t);
    string x;
    getline(cin,x);
    getline(cin,x);
    for(int a=1; a<=t; a++)
    {
        mx=0;
        while(true)
        {
            getline(cin,x);
            int len=x.size();
            if(!len)
                break;
            int val=0,i=2;
            seen[x[0]-'A']=1;
            for(; i<len; i++)
            {
                if(x[i]==' ')
                    break;
                val=(val*10)+(x[i]-'0');
            }
            cost[x[0]-'A']=val;
            for(int j=i+1; j<len; j++)
            {
                if(x[j]!=' '){
                    v[x[j]-'A'].push_back(x[0]-'A');
                    ind[x[0]-'A']++;seen[x[j]-'A']=1;
                }
            }

        }
        for(int i=0;i<26;i++)
        {
            if(seen[i] && ind[i]==0){
                memset(tot,0,sizeof(tot));
                dfs(i,cost[i]);

            }
        }

        for(int i=0;i<28;i++){
            v[i].clear();seen[i]=0,ind[i]=0;///seen[i]=0;ind[i]=0;tot[i]=0;
        }
        printf("%d\n",mx);
        if(a!=t)printf("\n");

    }
    return 0;
}
