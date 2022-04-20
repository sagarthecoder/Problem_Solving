#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,p,q,x,ans=0,sum=0;scanf("%d %d %d",&n,&p,&q);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(ans<p && sum+x<=q){
                sum+=x;ans++;
            }
        }
        printf("Case %d: %d\n",a,ans);
    }
    return 0;
}
