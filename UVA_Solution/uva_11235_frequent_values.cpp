#include <bits/stdc++.h>
#define ll long long
using namespace std;
int pos[100004],ara2[100005];
int bap[100002][17];
int main()
{
    int n,k,x,y;
    while(true)
    {
        scanf("%d",&n);if(!n)break;
        scanf("%d",&k);
        int ara[n+2];for(int i=1;i<=n;i++)scanf("%d",&ara[i]);
        ara2[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(ara[i]==ara[i-1])ara2[i]=ara2[i-1]+1;
            else ara2[i]=1;
            ///cout<<"1s2 = "<<i <<" = "<<ara2[i]<<endl;
        }
        int posCk=n;
        pos[n]=n;
        for(int i=n-1;i>=1;i--){
            if(ara[i]==ara[i+1]){
                ara2[i]=ara2[i+1];
                pos[i]=posCk;
            }
            else{
                pos[i]=i;
                posCk=i;
            }
        }
       /// cout<<"break "<<endl<<endl;
        /*for(int i=1;i<=n;i++){
           /// cout<<"pos = "<<i <<" = "<<pos[i]<<endl;
            cout<<"ara2 = "<<i<<" = "<<ara2[i]<<endl;
        }*/
        int log=0;
        if(n!=0)log=ceil((double)log2(n)*1.0);
        for(int i=1;i<=n;i++)
        {
            bap[i][0]=ara2[i];
            //cout<<"bp1 = "<<i<<" = "<<bap[i][0]<<endl;
        }

        for(int i=1;i<=log;i++)
        {
            for(int j=1;j+(1<<i)<=n+1;j++)bap[j][i]=max(bap[j][i-1],bap[j+(1<<(i-1))][i-1]);
        }
        while(k--)
        {
            scanf("%d %d",&x,&y);
            log=log2(y-x+1);
            ///int  mini=max(bap[x][log],bap[y-(1<<log)+1][log]);
            ///cout<<"mini = "<<mini<<endl;
            int ck=pos[x];
            ///cout<<"ckpos = "<<ck<<endl;
            if(ck>=y || x==y){
                printf("%d\n",y-x+1);continue;
            }
            ck=ck-x+1;
            int ck2=pos[y]-ara2[y]+1;
            ck2=y-ck2+1;
            int maxi=max(ck,ck2);
            x=pos[x]+1;
            y=pos[y]-ara2[y];
            if(x>y){
                printf("%d\n",maxi);continue;
            }
           /// cout<<"x = "<<x<<" y = "<<y<<endl;
            log=log2(y-x+1);
            maxi=max(maxi,max(bap[x][log],bap[y-(1<<log)+1][log]));
            printf("%d\n",maxi);


        }

    }
    return 0;
}
