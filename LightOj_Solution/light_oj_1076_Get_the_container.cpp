#include <bits/stdc++.h>
#define ll long long
using  namespace std;
int ara[1003],n,m;
bool go(int x)
{
    int cnt=0,p=0;
    for(int i=0;i<n;i++)
    {
        if(ara[i]>x)return false;
        if(cnt+ara[i]==x){
            p++;
            cnt=0;
        }
        else if(cnt+ara[i]>x){
            p++;cnt=ara[i];
        }
        else cnt+=ara[i];
    }
    if(cnt)p++;
    ///cout<<"x = "<<x<<" , pos = "<<p<<endl<<endl;;
    return p<=m;
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%d %d",&n,&m);
        int L=0,H=0,val,mid,mx=0;
        for(int i=0;i<n;i++){scanf("%d",&ara[i]);
        H+=ara[i];
        mx=max(mx,ara[i]);
        }
        if(m>=n){
            printf("Case %d: %d\n",a,mx);
        }

        else{
        while(L<=H)
        {
             mid=(L+H)>>1;
             ///cout<<"L ="<<L<<",  H = "<<H<<endl;
            if(go(mid)){
                    val=mid;
                    H=mid-1;
            }
            else L=mid+1;
        }
        printf("Case %d: %d\n",a,val);
        }
    }
    return 0;
}
