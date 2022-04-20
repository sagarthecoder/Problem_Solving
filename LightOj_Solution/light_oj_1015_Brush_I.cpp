#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,x,ans=0;scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            if(x>0)ans+=x;
        }
        printf("Case %d: %d\n",a,ans);
    }
    return 0;
}
