#include<cstdio>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#define ll long long
#define sf scanf
#define pf printf
#define pb push_back
#define ll long long
using namespace std;
int ara[10000000];
int main()
{
    int t,a,i;scanf("%d",&t);
    for( a=1;a<=t;a++)
    {
        int n,m,k,cnt=0,low=1,res,mini=1000000000,len=0;
        scanf("%d %d %d",&n,&m,&k);
        int seen[1004];
        memset(seen,0,sizeof(seen));
       // seen[1]=1,seen[2]=1,seen[3]=1;
        ara[1]=1,ara[2]=2,ara[3]=3;
        for( i=4;i<=n;i++)
        {
            ara[i]=(((ara[i-1])%m)+(ara[i-2]%m)+(ara[i-3])%m)%m +1;
            /*if(ara[i]<=k && seen[ara[i]]==false){
                seen[ara[i]]=true;
                cnt++;
            }*/
        }
        ///cout<<"ok"<<endl;
       /// for( i=1;i<=n;i++)cout<<ara[i]<<endl;
        i=1,cnt=0,len=0;
        while(i<=n+1)
        {
            if(cnt==k){
                mini=min(mini,len);
                len--;
                if(seen[ara[low]]>0){
                    seen[ara[low]]--;
                    if(seen[ara[low]]==0)
                    cnt--;

                }
                ///cout<<"min = "<<mini<<endl;
                ///cout<<" cnt & k ="<<cnt<<" "<<k<<endl;
                low++;
            }

            else if(ara[i]<=k && i<=n){
                seen[ara[i]]++;
                if(seen[ara[i]]==1 && ara[i]!=0)cnt++;
                i++;
                len++;
            }
            else {len++,i++;
            }
        }
        if(mini==1000000000)printf("Case %d: sequence nai\n",a);
        else
            printf("Case %d: %d\n",a,mini);


    }
    return 0;
}
