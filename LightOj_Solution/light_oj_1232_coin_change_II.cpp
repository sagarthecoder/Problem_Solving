#include <stdio.h>
#define ll  long
ll banabo[10003];
int ara[103];

int main()
{
    int t,a,i,j ;scanf("%d",&t);
    for( a=1;a<=t;a++)
    {
        int n,k;scanf("%d %d",&n,&k);
        for( i=0;i<n;i++)scanf("%d",&ara[i]);
        banabo[0]=1;
        for( i=1;i<=k;i++)banabo[i]=0;
        for( i=0;i<n;i++)
            for( j=1;j<=k;j++)if(j>=ara[i])banabo[j]=((banabo[j])%100000007+(banabo[j-ara[i]])%100000007)%100000007;
            printf("Case %d: %ld\n",a,banabo[k]);

    }
    return 0;
}
