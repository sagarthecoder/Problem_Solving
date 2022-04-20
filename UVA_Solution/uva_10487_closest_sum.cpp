#include <bits/stdc++.h>
using namespace std;
struct data
{
    int man,pos;
};
bool comp(data u,data u1)
{
    return u.man<u1.man;
}
int main()
{
    int a=1,n;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)break;
        int ara[n+2],x,sz=0;
        vector<int>v;
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);

        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            int sum=ara[i]+ara[j];
            ///if(seen[sum]==0){
              v.push_back(sum);
              sz++;
              //seen[sum]=1;
            ///}
        }
        sort(v.begin(),v.end());
        int m;scanf("%d",&m);
        printf("Case %d:\n",a);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            printf("Closest sum to %d is ",x);
            int L=lower_bound(v.begin(),v.end(),x)-v.begin();
            int U=upper_bound(v.begin(),v.end(),x)-v.begin();
            vector<data>ah;
            if(L!=sz){
                ah.push_back({abs(v[L]-x),L});
            }
            if((L-1)!=-1){
                ah.push_back({abs(v[L-1]-x),L-1});
            }
            if(U!=sz)ah.push_back({abs(v[U]-x),U});
            if(U-1!=-1)ah.push_back({abs(v[U-1]-x),U-1});
            sort(ah.begin(),ah.end(),comp);
            printf("%d.\n",v[ah[0].pos]);
        }
        a++;
    }
    return 0;
}
