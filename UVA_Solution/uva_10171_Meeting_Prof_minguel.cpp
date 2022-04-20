#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data{
    int v,cost;
    friend bool operator < (data a,data b)
    {
        return a.cost>b.cost;
    }
};
vector<data>Young[28];
vector<data>Old[28];
int n,c;
char a,b,x,y;
int costYoung[28],costOld[28];
void djkYoung()
{
     priority_queue<data>q;
     q.push({(x-'A'),0});
     costYoung[x-'A']=0;
     while(!q.empty()){
        data t=q.top();
        q.pop();
         if(t.cost>costYoung[t.v])continue;
         for(int i=0;i<Young[t.v].size();i++)
         {
             int asus=Young[t.v][i].v;
             if(costYoung[asus]>costYoung[t.v]+Young[t.v][i].cost){
                costYoung[asus]=costYoung[t.v]+Young[t.v][i].cost;
                q.push({asus,costYoung[asus]});
             }

         }
     }

}

void djkOld()
{
     priority_queue<data>q;
     q.push({(y-'A'),0});
     costOld[y-'A']=0;
     while(!q.empty()){
        data t=q.top();
        q.pop();
         if(t.cost>costOld[t.v])continue;
         for(int i=0;i<Old[t.v].size();i++)
         {
             int asus=Old[t.v][i].v;
             if(costOld[asus]>costOld[t.v]+Old[t.v][i].cost){
                costOld[asus]=costOld[t.v]+Old[t.v][i].cost;
                q.push({asus,costOld[asus]});
             }

         }
     }

}
int main()
{
    while(true){
        cin>>n;if(!n)break;
        int seen[27];memset(seen,0,sizeof(seen));
        for(int i=0;i<=28;i++)costYoung[i]=1000000000,costOld[i]=1000000000;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>x>>y>>c;
            int x1=x-'A',y1=y-'A';
            if(a=='Y'){
                Young[x1].push_back({y1,c});
                if(b=='B')Young[y1].push_back({x1,c});
            }
            else{
                Old[x1].push_back({y1,c});
                if(b=='B')Old[y1].push_back({x1,c});
            }
        }
        cin>>x>>y;
        djkYoung();djkOld();
        for(int i=0;i<26;i++){
            if(costYoung[i]!=1000000000){
                seen[i]=1;
            }
        }
        vector<int>olala;
        int sz=0;
        for(int i=0;i<26;i++){
            if(costOld[i]!=1000000000 && seen[i]){
                olala.push_back(i);sz++;
            }
        }
        int mini=1000000000;
        for(int i=0;i<sz;i++){
            mini=min(costOld[olala[i]]+costYoung[olala[i]],mini);
        }
        if(mini==1000000000)cout<<"You will never meet."<<endl;
        else{
            cout<<mini<<" ";
            bool ck=false;
           // cout<<"sz = "<<sz<<endl;
            for(int i=0;i<sz;i++){

                if(costOld[olala[i]]+costYoung[olala[i]]==mini){
                   char ch=olala[i]+65;
                   if(ck)cout<<" ";
                   cout<<ch;ck=true;

                }
            }
            cout<<endl;
        }
        for(int i=0;i<=26;i++)Young[i].clear(),Old[i].clear();





    }
    return 0;
}
