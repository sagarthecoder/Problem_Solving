#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ara[30];
int main()
{
    int t;
    scanf("%d",&t);
    for(int a=1; a<=t; a++)
    {
        int n,k,cnt=0;
        scanf("%d %d",&n,&k);
        for(int i=0; i<n; i++)
        {
            ara[i]=i;
        }



        printf("Case %d:\n",a);

        do
        {
            for(int i=0;i<n;i++)printf("%c",char(65+ara[i]));printf("\n");
            cnt++;if(cnt==k)break;
        }
        while (next_permutation(ara, ara + n));
    }
    return 0;
}
