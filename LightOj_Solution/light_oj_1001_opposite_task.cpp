#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n;scanf("%d",&n);
        ///printf("Case %d: ",a);
        if(n==0)printf("0 0\n");
        else if(n<=10)printf("%d %d\n",1,n-1);
        else printf("%d %d\n",10,n-10);
    }
    return 0;
}
