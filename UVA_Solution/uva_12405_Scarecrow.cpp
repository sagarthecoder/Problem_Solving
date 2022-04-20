#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int len,ans=0;scanf("%d",&len);
        char x[120];scanf("%s",x);
        for(int i=0;i<len;i++)
        {
            if(x[i]=='.'){
                if(i+1<len){
                    if(x[i+1]=='.' || x[i+1]=='#'){
                        i+=2;
                    }
                    else i++;
                }
                else i++;
                ans++;
            }
        }
        printf("Case %d: %d\n",a,ans);
    }
    return 0;
}
