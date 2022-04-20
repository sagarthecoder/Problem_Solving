#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t,n;scanf("%d",&t);

    for(int a=1;a<=t;a++)
    {
        scanf("%d",&n);
        int pos[n+2],cnt=0;
        int ara[n+2];
        for(int i=1;i<=n;i++){
            scanf("%d",&ara[i]);
            pos[ara[i]]=i;
        }
        for(int i=1;i<=n;i++){
            if(ara[i]!=i){
                int ck=pos[i];pos[ara[i]]=ck;pos[i]=i;
                swap(ara[i],ara[ck]);cnt++;
            }
        }
        printf("Case %d: %d\n",a,cnt);
    }
    return 0;
}
