#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <set>
#include <iterator>
using namespace std;
vector<string>node;
map<string,int>seen;
map<string,int>indegree;
vector<string>result;
map<string,vector<string> >v;
int main()
{
    int n,m,no=1;
    while(cin>>n)
    {
        string x,y;
        for(int i=0;i<n;i++){
            cin>>x;
            node.push_back(x);
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            v[x].push_back(y);
            indegree[y]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(indegree[node[j]]==0 && seen[node[j]]==0)
                {
                    result.push_back(node[j]);
                    for(int k=0;k<v[node[j]].size();k++)indegree[v[node[j]][k]]--;
                    seen[node[j]]=1;
                    break;
                }
            }
        }
        //cout<<"size "<<result.size()<<endl;
        bool ck=false;
        cout<<"Case #"<<no<<": ";
        cout<<"Dilbert should drink beverages in this order: ";
        for(int i=0;i<result.size();i++){
            if(ck==true)cout<<" ";
            ck=true;
            cout<<result[i];
        }
        cout<<".";
        cout<<endl<<endl;
        no++;
        seen.clear();
        node.clear();
        v.clear();
        result.clear();
        indegree.clear();

    }
    return 0;
}
