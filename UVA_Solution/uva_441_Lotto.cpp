#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;bool ck=false;
    while(true)
    {
        scanf("%d",&n);
        if(!n)break;
        if(ck)printf("\n");
        ck=true;
        int ara[n+1];
        int cnt=6;
        for(int i=0;i<n;i++)cin>>ara[i];
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
            for(int l=k+1;l<n;l++)
            for(int m=l+1;m<n;m++)
            for(int o=m+1;o<n;o++)
            printf("%d %d %d %d %d %d\n",ara[i],ara[j],ara[k],ara[l],ara[m],ara[o]);
    }
    return 0;
}
