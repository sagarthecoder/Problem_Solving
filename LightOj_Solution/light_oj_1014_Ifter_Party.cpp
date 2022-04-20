#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
       int P,L;
        bool ck=false;
        scanf("%d %d",&P,&L);
        printf("Case %d: ",a);
       /// vector<ll>v1;

        P-=L;
        int sq=sqrt(P);
       int ara1[(sq*2)+2];
        int ara2[(sq*2)+1];
        int  cnt=1,a1=0,a2=0;
        while(true)
        {
            /*for(int m=0;m<sq;m++){
                cout<<"ok"<<endl;
            }*/
               /// break;
               for( cnt=1;cnt<=sq;cnt++){
            if(P%cnt==0)
            {
                ll A=P/cnt;
                /*if(cnt>L){
                    v1.push_back(cnt);
                }*/
                if(A<=cnt){
                       if(A==cnt && A>L){
                        ara1[a1]=A;
                        a1++;
                       }
                        break;
                }
                if(cnt>L){ara1[a1]=cnt;
                a1++;
                }
                if(A>L && A!=cnt){
                    ara2[a2]=A;
                    a2++;
                }
            }
           /// cnt++;
               }
               break;
        }
        ///sort(v1.begin(),v1.end());
        //int sz=v1.size();
        if(a1==0 && a2==0)printf("impossible");
        else
        {
            for(int i=0;i<a1;i++){
                if(ck)printf(" ");
                printf("%d",ara1[i]);
                ck=true;
            }
            for(int i=a2-1;i>=0;i--){
                if(ck)printf(" ");
                printf("%d",ara2[i]);
                ck=true;
            }
        }
        printf("\n");
       /// Case 1: 1 2 5 10
        /// 2147483647

    }
    return 0;
}
