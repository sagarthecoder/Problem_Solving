#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mx=1000000,x,y;
bitset<1000001>b;
bool go()
{
    for(int i=x;i<y;i++)
    {
        if(b[i]==1)return true;
        b.set(i);
    }
    return false;
}
int main()
{
    int n,m;
    while(true)
    {
        scanf("%d %d",&n,&m);
        b.reset();
        int  z;
        if(n+m==0)break;
        bool ck=false;
        for(int i=0;i<n;i++){
             scanf("%d %d",&x,&y);
            if(ck)continue;
            if(go())ck=true;


        }
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&x,&y,&z);
            if(ck)continue;
            while(x<mx && !ck)
            {
                if(go()){
                    ck=true;break;
                }
                x+=z;
                y+=z;
                y=min(y,mx);
            }
        }
        if(ck)printf("CONFLICT\n");
        else printf("NO CONFLICT\n");
    }
    return 0;
}
