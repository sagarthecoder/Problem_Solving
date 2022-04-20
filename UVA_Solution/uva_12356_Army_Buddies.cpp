#include <bits/stdc++.h>
#define ll long long
using namespace std;
int pre[100005],post[100005];
int main()
{
    int n,m,x,y;
    while(true)
    {
        scanf("%d %d",&n,&m);
        if(!n && !m)break;
        for(int i=1;i<=n;i++){
            pre[i]=i-1;
            post[i]=i+1;
        }
        while(m--)
        {
            scanf("%d %d",&x,&y);
            int ok1=0,ok2=n+1;
            post[pre[x]]=post[y];
             ok2=post[pre[x]];
            pre[post[y]]=pre[x];
            ok1=pre[post[y]];
            if(ok1==0){
                printf("* ");
            }
            else printf("%d ",ok1);
            if(ok2==n+1){
                printf("*\n");
            }
            else printf("%d\n",ok2);

        }
        printf("-\n");
    }
    return 0;
}
