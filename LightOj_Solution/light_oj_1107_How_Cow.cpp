#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
        int x1,m,x,y,y1,x2,y2;scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&m);
        printf("Case %d:\n",a);
        while(m--)
        {
            scanf("%d %d",&x,&y);
            if(x>x1 && x<x2 && y>y1 && y<y2)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
