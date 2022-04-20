#include <bits/stdc++.h>
using namespace std;
int ara[200009];
int put[200009*4],sum=0;
void build(int node,int i,int j)
{
    if(i==j){put[node]=ara[i];
     return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(i+j)>>1;
    build(left,i,mid);
    build(right,mid+1,j);
    put[node]=put[left]+put[right];
    ///cout<<"put = "<<put[node]<<endl;
}
void update(int node,int i,int j,int v,int value)
{

    if(j<v || i>v)return;
    if(i==v && i==j){
     put[node]=value;
     return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(i+j)>>1;
    update(left,i,mid,v,value);
    update(right,mid+1,j,v,value);
    put[node]=put[left]+put[right];
    ///cout<<"put = "<<put[node]<<endl;
}
int query(int node,int i,int j,int q1,int q2)
{
    if(j<q1 || i>q2){
           /// cout<<"nodeRETurn= "<<node<<endl;
    ///cout<<"nodeRERETurn"<<put[node]<<endl;
            return 0;
    }
    if(i>=q1 && j<=q2){
            ///cout<<"nodeIN= "<<node<<endl;
   /// cout<<"nodeRESSS "<<put[node]<<endl;
            return put[node];
    }
    int left=node<<1;
    int right=left+1;
    int mid=(i+j)>>1;
   int p= query(left,i,mid,q1,q2);
   int q= query(right,mid+1,j,q1,q2);
    ///cout<<"node = "<<node<<endl;
    ///cout<<"sumPQ = "<<p+q<<endl;
    ///return put[left]+put[right];
    return (p+q);

}
int main()
{
    int n,t=1;
    bool ck=false;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)break;
        if(ck==true)printf("\n");
        ck=true;
        printf("Case %d:\n",t);
        for(int i=1;i<=n;i++)scanf("%d",&ara[i]);
        build(1,1,n);
        while(true){
        char x[10];int v1,v2;
        scanf("%s",x);
         if(strcmp(x,"END")==0)break;
         scanf("%d %d",&v1,&v2);
         if(strcmp(x,"S")==0){
            update(1,1,n,v1,v2);
         }
         else{
            sum=0;
            int ans=query(1,1,n,v1,v2);
            printf("%d\n",ans);
         }
        }

        t++;
    }
    return 0;
}
