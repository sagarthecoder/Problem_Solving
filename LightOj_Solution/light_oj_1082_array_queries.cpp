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
#define wow 10000000
using namespace std;
#define ll long long int
//int value=wow;
int ara[100001];
int tree[400005];
void segment(int node,int i,int j)
{
    if(i==j){
        tree[node]=ara[i];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(i+j)/2;
    segment(left,i,mid);
    segment(right,mid+1,j);
    tree[node]=min(tree[left],tree[right]);
    //cout<<tree[node]<<endl;


}
int res(int node,int i,int j,int rng1,int rng2)
{
    //cout<<i<<" "<<j<<endl;
    if((i<rng1 && j<rng1)|| (i>rng2 && j>rng2))
        return wow;
        //cout<<1<<endl;
    if(i>=rng1 && j<=rng2)return tree[node];
    int left=node*2;
    int right=(node*2)+1;
    int mid=(i+j)/2;
    int p=res(left,i,mid,rng1,rng2);
    int q=res(right,mid+1,j,rng1,rng2);
    //cout<<p<<" "<<q<<"  "<<i<<" "<<j<<" "<<mid<<endl;
    return  min(p,q);

}
int main()
{
    int t,n,q,rng1,rng2;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d %d",&n,&q);
        //memset(ara,0,sizeof(ara));
        //memset(tree,0,sizeof(tree));");
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        segment(1,0,n-1);
        //cout<<"Case "<<k<<":"<<endl;
        printf("Case %d:\n",k);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&rng1,&rng2);
            //value=wow;
            int ans=res(1,0,n-1,rng1-1,rng2-1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
