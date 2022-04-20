#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
map<int,int>colour;
map<int,int>ck;
int ans;
void bfs(int x,map<int,vector<int> >graph)
{
    queue<int>q;
    int res=-1;
    ans=0;
    colour[x]=1;
    q.push(x);
    while(!q.empty()==true)
    {
        int top=q.front();
        for(int i=0;i<graph[top].size();i++)
        {
            int taken=graph[top][i];
            if(ck[taken]!=2 && taken!=x){
            if(colour[top]==colour[taken])
            {
                ans=1;
                break;
            }
            //cout<<res<<endl;
            colour[taken]=colour[top]+1;
            q.push(taken);
            }
        }
        //res=
        ck[top]=2;
        if(ans==1)
            break;
        q.pop();
    }
}
int main()
{
    int m,n,e,i,j,res,x,y;
    while(1)
    {
        cin>>n>>e;
        if(n==0)
            break;
        map<int,vector<int> >graph;
        for(i=0;i<e;i++)
        {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        bfs(0,graph);
        if(ans==1)
            cout<<"NOT BICOLORABLE."<<endl;
        else
            cout<<"BICOLORABLE."<<endl;
        graph.clear();
        ck.clear();
        colour.clear();
        ans=0;


    }
    return 0;
}
