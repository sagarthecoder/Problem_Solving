#include <bits/stdc++.h>
#define ll long long
#define mx 5000050000
using namespace std;
struct data
{
    ll x;
    friend bool operator<(data i,data j)
    {
        return i.x>j.x;
    }
};
int main()
{
    int n;
    while(true)
    {
        priority_queue<data>q;
        cin>>n;if(n==0)break;
        ll y;
        ll res=0,ans=0;
        bool ck=false;
        for(int i=0;i<n;i++)
        {
            cin>>y;q.push({y});
        }
        q.push({mx});
        while(!q.empty())
        {
           ll top1=q.top().x;q.pop();
           ll top2=q.top().x;q.pop();
           if(top2==mx){
            top2=0;
            ck=true;
           }
           res=top1+top2;
           //cout<<"top1,top2,res = "<<top1<<" "<<top2<<" "<<res<<endl;
           //ans+=res;
           if(!ck){q.push({res});
           ans+=res;
           }

        }
        cout<<ans<<endl;
    }
    return 0;
}
