#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    while(true)
    {
        int t,L,W,H;scanf("%d",&t);
        if(!t)break;
        int mx=0,vol;
        for(int i=1;i<=t;i++)
        {
            scanf("%d %d %d",&L,&W,&H);
            if(H>mx){
                mx=H;
                vol=L*W*H;
            }
            else if(H==mx && L*W*H>vol){
                vol=L*W*H;
            }
        }
        printf("%d\n",vol);
    }
    return 0;
}
