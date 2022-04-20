#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n;scanf("%d",&n);int ara[n+2];
        int maxi=n-1;bool ck=false;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
            if(ara[i]<n){
                ara[i]=max(ara[i],maxi-ara[i]);
            }
            else ck=true;
        }
        printf("Case %d: ",a);
        sort(ara,ara+n);int cnt=0;
        if(ck==false)
        for(int i=0;i<n-1;i++){
            if(ara[i]==ara[i+1])cnt++;
            else cnt=0;
            if(cnt>=2 ||ara[i]>=n){
                ck=true;break;
            }
        }
        if(cnt>=2)ck=true;
        if(ck==true){
            printf("no\n");
        }
        else printf("yes\n");
    }
    return 0;
}
