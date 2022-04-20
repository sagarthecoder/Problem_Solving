#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
map<int,int>rupa;
vector<int>saikat;
int res;
void bfs(int a,int b,map<int,vector<int> >sagar)
{
    queue<int>q;
    int ans=0;
    res=0;
    q.push(a);
    rupa[a]=0;
    while(q.empty()==false)
    {
        int top=q.front();
        for(int i=0;i<sagar[top].size();i++)
        {
            int taken=sagar[top][i];
            if(rupa[taken]==0 && taken!=a)
            {
                rupa[taken]=rupa[top]+1;
                res=rupa[taken];
                if(taken==b){
                    ans=1;
                    break;
                }
                q.push(taken);
            }
        }
        if(ans==1)
            break;
        q.pop();
    }
}
void gap(int x)
{
    if(x<10)
        cout<<" ";
}
int main()
{
    int x,y,z,i,j,w,ck,t=1;
    while(cin>>x)
    {
        int a[1000],b[1000];
        map<int,vector<int> >sagar;
        for(i=1;i<=x;i++)
        {
            cin>>y;
            sagar[1].push_back(y);
            sagar[y].push_back(1);
        }
        for(i=2;i<=19;i++)
        {
            cin>>z;
            for(j=1;j<=z;j++)
            {
                cin>>w;
                sagar[i].push_back(w);
                sagar[w].push_back(i);
            }
        }
        cin>>ck;
        for(i=0;i<ck;i++)
        {
            cin>>a[i]>>b[i];
            bfs(a[i],b[i],sagar);
            saikat.push_back(res);
            rupa.clear();

        }
        cout<<"Test Set #"<<t<<endl;
        for(i=0;i<saikat.size();i++)
        {
            gap(a[i]);
            cout<<a[i]<<" "<<"to"<<" ";
            gap(b[i]);
            cout<<b[i]<<":";
            gap(saikat[i]);
            cout<<saikat[i]<<endl;

        }
        t++;
        cout<<endl;
        sagar.clear();
        saikat.clear();
    }
    return 0;
}

