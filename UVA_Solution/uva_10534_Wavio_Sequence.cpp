#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int ara[n+1];
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        int LIS[n+1],inc[n+1],L=0,D=0,LDS[n+1];
        vector<int>dec;
        vector<int>ara2(ara,ara+n);
        reverse(ara2.begin(),ara2.end());
        reverse(dec.begin(),dec.end());
        for(int k=0;k<n;k++){

            if(k==0){
                LDS[D]=ara2[k];
                dec.push_back(D+1);
            }
            else if(ara2[k]>LDS[D]){
                D++;
                dec.push_back(D+1);
                LDS[D]=ara2[k];
            }
            else{
                int pos=lower_bound(LDS,LDS+D+1,ara2[k])-LDS;
                dec.push_back(pos+1);
                LDS[pos]=ara2[k];
            }
            if(k==0){
                LIS[L]=ara[k];
                inc[k]=L+1;

            }
            else if(ara[k]>LIS[L]){
                L++;
                LIS[L]=ara[k];
                inc[k]=L+1;
            }
            else{
                int low=lower_bound(LIS,LIS+L+1,ara[k])-LIS;
                inc[k]=L+1;
                LIS[low]=ara[k];
            }
        }
        reverse(dec.begin(),dec.end());
        ///for(int i=0;i<n;i++)cout<<"d = "<<dec[i]<<endl;
        ///for(int i=0;i<n;i++)cout<<"L  = "<<inc[i]<<endl;
        int maxi=0;
        for(int i=n-1;i>=0;i--)
        {
            if(inc[i]>=dec[i]){
                maxi=max(maxi,(dec[i]*2)-1);
            }
        }
        printf("%d\n",maxi);
    }
    return 0;
}
