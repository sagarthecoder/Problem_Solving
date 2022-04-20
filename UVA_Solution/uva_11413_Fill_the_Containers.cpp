#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ara[1001],sum=0;
bool sagar(int banabo)
{
    int cnt=0,jug=0;
    for(int i=0;i<n;i++)
    {
        jug+=ara[i];
        if(ara[i]>banabo)return false;
        if(i==n-1){
            if(jug>banabo)cnt++;
            break;
        }
        /*if(i==n-1){
            cout<<"banabo  ="<<banabo<<"  jug ="<<jug<<endl;
            if(jug>banabo)return false;
            break;
        }*/
        if(jug==banabo){
            cnt++;jug=0;
        }
        else if(jug>banabo){
            cnt++;
            jug=ara[i];
        }
    }
    if(cnt<m)return true;
    return false;
    ///return (cnt<=m);
}
int go()
{
    int low=0,high=sum,mid,saikat;
    while(low<=high)
    {
         mid=(low+high)>>1;
        bool taken=sagar(mid);
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
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&ara[i]);
            sum+=ara[i];
        }
        if(m==1){
            printf("%d\n",sum);
            continue;
        }
       int ans=go();
       printf("%d\n",ans);

    }
    return 0;
}
