#include<cstdio>
#include<sstream>
#include<cstdlib>
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
using namespace std;
map<int,map<int,int> >graph;
vector<int>saikat;
map<int,map<int,char> >wow;
map<char,int>counting;
map<char,int>alfa;
vector<char>sagar;
int h,m,put1,put2;
char take;
void dfs(int x,int y)
{
    int dx[]={1,-1,0,0};
    int dy[]={0,0,-1,1};
    if(graph[x][y]==1)return;
    graph[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int fx=dx[i]+x;
        int fy=dy[i]+y;
        if(fx>=0 && fy>=0 && fx<h && fy<m && (fx!=put1 || fy!=put2)){
            if(graph[fx][fy]==0 && wow[fx][fy]==take)
            {
                //graph[fx][fy]=2;
                //cout<<wow[fx][fy]<<" ";
                dfs(fx,fy);
            }
        }
    }
   // cout<<endl;
}
int main()
{
    int n,i,j,k,w,temp;
    char u,temp2;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>h>>m;
        if(h==0 || m==0)
            cout<<"World #"<<i<<endl;
        else{
        for(j=0;j<h;j++)
        for(k=0;k<m;k++){
            cin>>u;
            if(alfa[u]==0)
            {
                sagar.push_back(u);
                alfa[u]=1;
                //cout<<u<<" ";
            }
            wow[j][k]=u;
        }
        sort(sagar.begin(),sagar.end());
       for(j=0;j<h;j++)for(k=0;k<m;k++){
        if(graph[j][k]==0)
        {
            take=wow[j][k];
            //cout<<take<<endl;
            put1=j,put2=k;
            dfs(j,k);
            graph[j][k]=1;
            counting[take]++;
            //cout<<take<<counting[take]<<endl;
        }
       }
       for(j=0;j<sagar.size();j++)saikat.push_back(counting[sagar[j]]);
       for(j=0;j<sagar.size()-1;j++)
       for(w=j+1;w<sagar.size();w++){
        if(saikat[j]==saikat[w]){
            if(sagar[j]>sagar[w])
                swap(sagar[j],sagar[w]);
        }
        else if(saikat[j]<saikat[w]){
            swap(saikat[j],saikat[w]);
        swap(sagar[j],sagar[w]);
        //cout<<saikat[j]<<" "<<saikat[w]<<endl;
        //cout<<sagar[j]<<" "<<counting[sagar[j]]<<" "<<sagar[w]<<" "<<counting[sagar[w]]<<endl;
        }
       }
       cout<<"World #"<<i<<endl;
       for(j=0;j<sagar.size();j++)
        cout<<sagar[j]<<": "<<saikat[j]<<endl;
        graph.clear();
        sagar.clear();
        saikat.clear();
        alfa.clear();
        counting.clear();
        wow.clear();
        }
    }
    return 0;
}
