#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ara[100005],n,mx=0;
int sagar(int x)
{
    int prev=0;
    for(int i=0;i<n;i++)
    {
        int bad=ara[i]-prev;
        if(bad>x)return false;
        if(bad==x)x--;
        if(x<0)return false;
        prev=ara[i];
    }
    if(x>=0)return true;
    return false;
}
int go()
{
    int low=0,high=mx,saikat;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        int taken=sagar(mid);
        if(taken){
            saikat=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return saikat;
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%d",&n);mx=0;
        for(int i=0;i<n;i++){
            scanf("%d",&ara[i]);
            mx=max(mx,ara[i]);
        }
        int ans=go();
        printf("Case %d: %d\n",a,ans);
    }
    return 0;
}
