#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int d,s;
    char ch;
};
struct data2
{
    int T,cnt;
};
bool comp(data u,data u1)
{
    if(u.d==u1.d && u.s==u1.s)return u.ch<u1.ch;
    if(u.d==u1.d)return u.s>u1.s;
    return u.d>u1.d;
}
int ara[20];
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        int n;cin>>n;
        stack<data2>q;
        memset(ara,0,sizeof(ara));
        vector<data>v;
        int x,y;char ch;
        for(int i=0;i<n;i++){
        cin>>x>>y>>ch;
        v.push_back({x,y,ch});
        }
        sort(v.begin(),v.end(),comp);
        int chur=0;
        ll ans=0;
        int beshi=0;bool ck=false;
        for(int i=0;i<n;i++)
        {

           //// cout<<"d = "<<v[i].d<<endl;
            if(v[i].s==1 && v[i].ch=='c'){chur++;
               beshi=v[i].d;
               if(ck==false){q.push({v[i].d,chur});
               ck=true;
               }
               else
               {
                   ///if(q.front()==v[i].d)q.front().cnt=chur;
                   if(q.top().T==v[i].d){
                   q.pop();
                   q.push({v[i].d,chur});
                   }
                   else q.push({v[i].d,chur});
               }
            }
            else if(v[i].s==0 && v[i].ch=='i'){

                    if(ck==true)
                    {
                         if(q.top().T==v[i].d){
                            int samne=q.top().T;
                            int C=q.top().cnt;
                            q.pop();
                            if(!q.empty()){
                                ans+=q.top().cnt;
                            }
                            q.push({samne,C});
                         }
                         else ans+=chur;
                    }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
