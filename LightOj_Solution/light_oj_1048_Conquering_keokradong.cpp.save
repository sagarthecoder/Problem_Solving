#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,ara[1003];
bool go(int x)
{
    int cnt=0,pos=0;
    for(int i=0;i<=n;i++)
    {
        if(ara[i]>x)return false;
        cnt+=ara[i];
        if(cnt>x)
        {
            pos++;
            cnt=ara[i];
        }
    }
    return (pos<=k);

}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int H=0,L=INT_MAX,mid,value,MX=0;
        scanf("%d %d",&n,&k);

        int ans[k+3];
        for(int i=0;i<=n;i++){scanf("%d",&ara[i]);
          L=min(L,ara[i]);
          H+=ara[i];
        }
        if(n==k){
            for(int i=0;i<=n;i++){ans[i]=ara[i];
            MX=max(MX,ara[i]);
            }

        }
        else{
        L=0,H=10000001;
        while(L<=H)
        {
            mid=(L+H)>>1;

            if(go(mid))
            {
               ///H=mid-1;
               value=mid;
               H=mid-1;
            }
            else L=mid+1;
        }

        int res=0,ind=0,ok=0;
        ///cout<<"value = "<<value<<endl;
        for(int i=0;i<=n;i++)
        {
            //res+=ara[i];
            ///cout<<"res + ar = "<<res+ara[i]<<endl;
            ///cout<<"value = "<<value<<endl;
            if(res+ara[i]>value){
                ans[ind]=res;
                res=ara[i];
                MX=max(MX,ans[ind]);
                ind++;
            }
            else if(res+ara[i]==value){
                ans[ind]=res+ara[i];
                MX=max(MX,ans[ind]);
                res=0;
                ind++;
            }
            else if(n-i+1==k+1-ind){
                ans[ind]=res+ara[i];
                res=0;ind++;
            }

            else res+=ara[i];
            /*else if(res==value){
                ara[ind]=res;res=0;
                MX=max(ara[ind],MX);
                ind++;
            }*/
        }
        if(res){
        ans[ind]=res;
        MX=max(MX,ans[ind]);
        }
        ///MX=value;
    }
        printf("Case %d: %d\n",a,MX);
        for(int i=0;i<=k;i++)printf("%d\n",ans[i]);

    }
    return 0;
    /*
    12 9
4
39
24
18
20
22
25
6
29
14
11
15
15
*/
}
