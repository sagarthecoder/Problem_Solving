#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ans[100003];
int go(int x)
{
    int ans=x;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0){
            while(x%i==0)x=x/i;
            ans-=ans/i;
        }
    }
    if(x>1)ans-=ans/x;
    return ans;
}
int main()
{
    for(int i=1;i<=100000;i++){
       ans[i]=go(i);
    }
    int t,x;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
    return 0;
}
