#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <iterator>
#include <cstring>
#include <cmath>
#define pii pair<int,int>
using namespace std;
map<int,map<int,int> >graph;
int p,q;
void dfs(int m,int n)
{
    int dx[]={1,-1,0,0,1,1,-1,-1};
    int dy[]={0,0,-1,1,-1,1,-1,1};
    for(int i=0;i<8;i++)
    {
        int newX=m+dx[i];
        int newY=n+dy[i];
        if(newX>=0 && newX<p && newY>=0 && newY<q)
        {
            if(graph[newX][newY]==2){
            graph[newX][newY]=1;
            dfs(newX,newY);
            }
        }

    }

}
int main()
{
    int n,m,i,j,res;
    char ch;
    while(1)
    {
        cin>>m>>n;
        res=0;
        if(m==0 && n==0)
            break;
            p=m;
            q=n;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++){
            cin>>ch;
            if(ch=='@')
                graph[i][j]=2;

            }
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
        {
            if(graph[i][j]==2){
                graph[i][j]=1;
                dfs(i,j);
                res++;
            }
        }
        cout<<res<<endl;
        graph.clear();
    }
    return 0;
}
