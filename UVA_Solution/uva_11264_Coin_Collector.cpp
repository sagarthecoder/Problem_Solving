#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int  t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        ll ara[n+2];
        for(int i=0;i<n;i++)scanf("%lld",&ara[i]);
        int cnt=0;
        ll sum=0;
        for(int i=0;i<n-1;i++)
        {
            if(sum+ara[i]<ara[i+1]){
                sum+=ara[i];cnt++;
            }
        }
        cnt++;
        printf("%d\n",cnt);

    }
    return 0;
}
