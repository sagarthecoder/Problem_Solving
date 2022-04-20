#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(true)
    {
        scanf("%d",&n);
        if(!n)break;
        int maxi=0,x,cnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            cnt+=x;
            maxi=max(cnt,maxi);
            if(cnt<0){
                cnt=0;
            }

        }
        maxi=max(maxi,cnt);
        if(maxi<=0)printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n",maxi);
    }
    return 0;
}
