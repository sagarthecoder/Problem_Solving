#include<bits/stdc++.h>
using namespace std;

struct node
{
    int a,b;
};

struct data
{
    node x;
    int cost;
};

int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
map<node,vector<

int main()
{
    int r,c,n,i,j;//n nodes,e denoting edges
    scanf("%d %d",&r,&c);
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d",&n);
            node x= {i,j};
            node y= {i+1,j+1};
            data t= {x,n};
            data s= {y,n};
            edges[t].push_back(s);
        }
    }

}
