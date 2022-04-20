#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n;scanf("%d",&n);
        int ara[n+2];ll cnt=0;
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        sort(ara,ara+n);
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++){
            int ans=ara[i]+ara[j];
            int low=lower_bound(ara,ara+n,ans)-ara;
            int diff=max(0,(low-(j)-1));
            cnt+=diff;
            }
        }
        printf("Case %d: %lld\n",a,cnt);
    }
    return 0;
}
