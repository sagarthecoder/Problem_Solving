#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll sum[16390];
int main()
{
    int  n;
    while(cin>>n)
    {
        int  x;
        memset(sum,0,sizeof(sum));
        int total=1<<n;
        for(int  i=0;i<total;i++)
        {
            cin>>x;
            for(int j=0;j<total;j++)
            {
                if(i==j)continue;
                int xx=i^j;
                if((xx&(-xx))==xx){
                    sum[j]+=x;
                }
            }
        }
        ll mx=0;
        for(int i=0;i<total;i++)
        {
            for(int j=0;j<total;j++)
            {
                if(i==j)continue;
                int xx=i^j;
                if((xx&(-xx))==xx){
                    mx=max(mx,sum[i]+sum[j]);
                }
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
