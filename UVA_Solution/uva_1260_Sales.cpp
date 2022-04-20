#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,res=0;scanf("%d",&n);
        int ara[n+2];
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        for(int i=1;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<i;j++)if(ara[i]>=ara[j])cnt++;
            res+=cnt;
        }
        printf("%d\n",res);
    }
    return 0;
}
