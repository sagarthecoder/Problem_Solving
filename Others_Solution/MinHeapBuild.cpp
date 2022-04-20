#include <bits/stdc++.h>
using namespace std;
void BuildHeap(int *ara,int n,int i)
{
    int smallest=i;
    int left=i<<1;
    int right=left+1;
    if(left<=n and ara[left]<ara[smallest])smallest=left;
    if(right<=n and ara[right]<ara[smallest])smallest=right;
    swap(ara[i],ara[smallest]);
    if(smallest!=i)BuildHeap(ara,n,smallest);
}
void MinHeap(int *ara,int n)
{
    int start=n>>1;
    for(int i=start;i>=1;i--)BuildHeap(ara,n,i);
}
int main()
{
    int n;cin>>n;
    int ara[n+1];
    for(int i=1;i<=n;i++)cin>>ara[i];
    MinHeap(ara,n);

    for(int i=1;i<=n;i++){
        cout<<"node no "<<i<<" = "<<ara[i]<<endl;
    }
    /*
    10
    35 33 42 10 14 19 27 44 26 31
    */
}
