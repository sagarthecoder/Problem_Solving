#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool ck=false;
    int t=1;
    while(true)
    {
        int n,x,L=0;scanf("%d",&n);
        vector<int>v;
        if(n==-1)break;
        v.push_back(n);
        for(int i=0;;i++)
        {
            scanf("%d",&n);
            if(n==-1)break;
            v.push_back(n);
        }
        reverse(v.begin(),v.end());
        int sz=v.size();
        int LIS[sz+2];
        for(int i=0;i<sz;i++)
        {
            if(i==0){
                LIS[L]=v[i];
            }
            else if( v[i]>LIS[L]){
                L++;
                LIS[L]=v[i];
            }
            else{
                int pos=lower_bound(LIS,LIS+L+1,v[i])-LIS;
                LIS[pos]=v[i];
            }
        }
        if(ck==true)printf("\n");ck=true;
        printf("Test #%d:\n",t);
        printf("  maximum possible interceptions: %d\n",L+1);
        t++;
    }
    return 0;
}
