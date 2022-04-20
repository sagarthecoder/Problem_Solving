#include <bits/stdc++.h>
#define ll long long
#define dd long double
using namespace std;
int seen[1000001];
bool comp(int u,int u1)
{
    return seen[u]>seen[u1];
}
int main()
{
    int n,x;
    bool olala=false;
    while(1)
    {
        scanf("%d",&n);if(!n)break;
        vector<int>v;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            seen[x]++;if(seen[x]==1)v.push_back(x);
            maxi=max(maxi,seen[x]);
        }
        sort(v.begin(),v.end(),comp);
        int sz=v.size();
        if(olala==true)printf("\n");
        olala=true;
        printf("%d\n",maxi);
        //for(int i=0;i<sz;i++)cout<<v[i]<<endl;
        vector<int>v2[maxi+1];
        for(int i=0;i<sz;i++)
        {
            if(seen[v[i]]!=0)
            {
                int make=i;
                for(int j=0;j<maxi;j++)
                {
                    v2[j].push_back(v[make]);
                    seen[v[make]]--;
                    if(seen[v[make]]==0)
                    {
                        bool omg=false;
                        while(true)
                        {
                            if(make+1>=sz)break;
                            make++;
                            if(seen[v[make]]==0)break;
                            omg=true;break;
                        }
                        if(!omg)break;
                    }
                }
            }
        }
        for(int i=0;i<maxi;i++)
        {
            bool dilaw=false;
            for(int j=0;j<v2[i].size();j++){
                if(dilaw)printf(" ");dilaw=true;
                printf("%d",v2[i][j]);
            }
            printf("\n");
        }

    }

    return 0;
}
