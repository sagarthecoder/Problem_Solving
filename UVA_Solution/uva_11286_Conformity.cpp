#include <bits/stdc++.h>
using namespace std;
struct data
{
    int a,b,c,d,e;
};
int main()
{
    int n;
    while(true)
    {
        scanf("%d",&n);
       /// map<int,map<int,int> >map<int,int> >seen;
        ///map<tuple<string,string>,int> m;
        map<int,map<int,map<int,map<int,map<int,int> > > > >seen;
        int ok[10009]={0};
        int maxi=0;
        vector<data>v;
        if(n==0)break;
        for(int i=0; i<n; i++)
        {
            int ara[5];
            for(int k=0;k<5;k++)scanf("%d",&ara[k]);
            sort(ara,ara+5);
            if(seen[ara[0]][ara[1]][ara[2]][ara[3]][ara[4]]==0)
            v.push_back({ara[0],ara[1],ara[2],ara[3],ara[4]});
            seen[ara[0]][ara[1]][ara[2]][ara[3]][ara[4]]++;
            maxi=max(maxi,seen[ara[0]][ara[1]][ara[2]][ara[3]][ara[4]]);
        }
        int res=0;
        int sz=v.size();
        for(int i=0;i<sz;i++)
        {
            ///seen[v[i].a][v[i].b][v[i].c][v[i].d][v[i].e];
            int fu=seen[v[i].a][v[i].b][v[i].c][v[i].d][v[i].e];
            if(fu==maxi)res++;
        }
        printf("%d\n",maxi*res);
    }
    return 0;
}
