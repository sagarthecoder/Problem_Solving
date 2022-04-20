#include <bits/stdc++.h>
using namespace std;
struct data
{
    int num,order;
};
vector<data>v;
int bsearch(int k,int songkha,int n)
{
    int low=0,high=n,mid;
    while(low<=high)
    {
         mid=(low+high)/2;
        if(v[mid].num<songkha)low=mid+1;
        else
            high=mid-1;

    }
    return low;
}
bool comp(data u,data u1)
{
    if(u.num==u1.num)return u.order<u1.order;
    return u.num<u1.num;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int x,k,songkha;
        //vector<int>v2;
        for(int i=0;i<n;i++){
            cin>>x;
            v.push_back({x,i});
        }
        sort(v.begin(),v.end(),comp);
        ///for(int i=0;i<v.size();i++)cout<<v[i].num<<" "<<v[i].order<<endl;
        for(int i=0;i<m;i++){
           cin>>k>>songkha;
           int mid=bsearch(k,songkha,n-1);
           ////cout<<"mid = "<<mid<<endl;
            if(mid+k-1<n){
                if(v[mid+k-1].num==songkha)cout<<1+(v[mid+k-1].order)<<endl;
                else cout<<0<<endl;
            }
            else cout<<0<<endl;
           }
        v.clear();
        //v2.clear();
    }
    return 0;
}
