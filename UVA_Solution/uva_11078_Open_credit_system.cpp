#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        int maxi=-1000000000,x,maxi2=-1000000000;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(i!=0)
            {
                maxi2=max(maxi2,maxi-x);
                ///cout<<"maxi2= "<<maxi2<<endl;
            }
            maxi=max(maxi,x);
        }
        printf("%d\n",maxi2);
    }
    return 0;
}
