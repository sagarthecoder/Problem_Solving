#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,d,r;
    while(true)
    {
        scanf("%d %d %d",&n,&d,&r);
        if(!n && !d && !r)break;
        int ara[n+2],ara2[n+2],ans=0;
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        for(int i=0;i<n;i++)scanf("%d",&ara2[i]);
        sort(ara,ara+n);
        sort(ara2,ara2+n,greater<int>());
        for(int i=0;i<n;i++){
            int res=ara[i]+ara2[i];
            if(res>d){
                ans+=(r*(res-d));
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
