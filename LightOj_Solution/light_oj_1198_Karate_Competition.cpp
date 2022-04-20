#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,cnt=0;scanf("%d",&n);
        int ara[n+2],ara2[n+2];
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        for(int i=0;i<n;i++)scanf("%d",&ara2[i]);

        sort(ara,ara+n);
        sort(ara2,ara2+n,greater<int>());

        for(int i=0;i<n;i++)
        {
            int one=-1,p1=-1,p2=-1;
            for(int j=0;j<n;j++)
            {
                if(ara2[j]<ara[i] && one<ara2[j] && ara2[j]!=100009){
                    one=ara2[j];
                    p1=j;
                }
            }
            if(p1!=-1){
                cnt+=2;ara2[p1]=100009;
                ara[i]=100004;
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ara[i]==ara2[j]){
                    cnt++;ara[i]=100004;ara2[j]=100009;break;
                }
            }
        }
        printf("Case %d: %d\n",a,cnt);

    }
    return 0;
}
