#include <bits/stdc++.h>
using namespace std;
struct data
{
    int v1,v2,w1;
};
int bap[1000009];
bool comp(data u,data u1)
{
    return u.w1<u1.w1;
}
int bapke(int x)
{
    if(bap[x]==x)return x;
    return bap[x]=bapke(bap[x]);
}
int main()
{
    int n,m;
    while(true)
    {
        scanf("%d %d",&n,&m);
        if(n==0 && m==0)break;
        int x,y,w,get,cnt=0;
        for(int i=0;i<=n;i++)bap[i]=i;
        vector<data>v;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&x,&y,&w);
            if(x<y)swap(x,y);
            v.push_back({x,y,w});

        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<m;i++)
        {
            int A=bapke(v[i].v1);
            int B=bapke(v[i].v2);
            if(A!=B)
            {
                cnt++;
                get=v[i].w1;
                bap[B]=A;
                if(cnt==n-1)break;
            }
        }
        if(cnt!=n-1)printf("IMPOSSIBLE\n");
        else printf("%d\n",get);
    }
    return 0;
}
