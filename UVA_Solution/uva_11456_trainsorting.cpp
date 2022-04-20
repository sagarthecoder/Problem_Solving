#include <bits/stdc++.h>
using namespace std;
int ara[2009],inc[2009],decr[2009];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,x,maxi=0;scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        for(int i=n-1;i>=0;i--)
        {
            inc[i]=1;
            //cout<<"fjfj"<<endl;
            for(int j=i+1;j<n;j++){
                if(ara[i]<ara[j])inc[i]=max(inc[i],inc[j]+1);
                ///cout<<"inc = "<<inc[i]<<endl;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            decr[i]=1;
            for(int j=i+1;j<n;j++){
                if(ara[i]>ara[j])decr[i]=max(decr[i],decr[j]+1);
            }
        }
        for(int i=0;i<n;i++)maxi=max(inc[i]+decr[i]-1,maxi);
        printf("%d\n",maxi);

    }
    return 0;
    /*
    15
10
3
13
1
4
9
8
12
6
14
5
7
2
0
11
*/
}
