#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int res,ans;
map<string,int>rupa;
void bfs(string a,string b,map<string,vector<string> >sagar)
{
    res=0;
    ans=2;
    queue<string>q;
    q.push(a);
    while(!q.empty()==true)
    {
        string top=q.front();
        for(int i=0;i<sagar[top].size();i++)
        {
            string take=sagar[top][i];
            if(rupa[take]==0)
            {
                rupa[take]=rupa[top]+1;
                res=rupa[take];
                if(take==b)
                {
                    ans=1;
                    break;
                }
                q.push(take);
            }
        }
        if(ans==1)
            break;
        q.pop();
    }

}
int main()
{
    int t,x,y,z,a,b,i,j,sum,ck;
    string s,u,v,start,finish;
    vector<int>saikat;
    vector<int>counting;
    cin>>t;
    cout<<"SHIPPING ROUTES OUTPUT"<<endl;
    cout<<endl;
    for(i=1;i<=t;i++)
    {
        map<string,vector<string> >sagar;
        map<string,int>cakking;
        cin>>x>>y>>z;
        for(j=1;j<=x;j++)
            {
                cin>>s;
                cakking[s]=1;
        }
        for(j=1;j<=y;j++)
        {
            cin>>u>>v;
            sagar[u].push_back(v);
            sagar[v].push_back(u);
        }
        for(j=0;j<z;j++)
        {
            cin>>ck>>start>>finish;
            counting.push_back(ck);
            if(cakking[start]==0 || cakking[finish]==0)
                saikat.push_back(-1);
            else if(start==finish)
            {
                saikat.push_back(-1);
            }
            else if(y==0)
                saikat.push_back(0);
            else{
            bfs(start,finish,sagar);
            if(ans==2)
                saikat.push_back(0);
            else
            saikat.push_back(res);
            }
            rupa.clear();

        }
        cout<<"DATA SET  "<<i<<endl<<endl;
        for(j=0;j<saikat.size();j++)
        {
            if(saikat[j]==0)
                cout<<"NO SHIPMENT POSSIBLE"<<endl;
            else if(saikat[j]==-1)
            cout<<"$0"<<endl;
            else
                {
                    sum=counting[j]*saikat[j]*100;
                    cout<<"$"<<sum<<endl;
                }
        }
        cout<<endl;
        sagar.clear();
        saikat.clear();
        counting.clear();

    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
