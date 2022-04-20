#include <bits/stdc++.h>
using namespace std;
vector<int>v[2501];
bool ck;
int maxi,pos;
void bfs(int x)
{
    queue<int>q;
    maxi=0,pos=1;
    ck=false;
    int ans[2501],seen[2501],bapke[2501];
    memset(seen,0,sizeof(seen));
    memset(ans,0,sizeof(ans));
    memset(bapke,0,sizeof(bapke));

    bool L=false;
    q.push(x);
    while(!q.empty())
    {
        int top=q.front();
        ///if(L==true){
        ///ans[bapke[top]]++;
        /*if(ans[bapke[top]]>maxi)maxi=ans[bapke[top]];
        cout<<"o kita = "<<bapke[top]<<endl;
        pos=seen[top]+1;
        }*/
        for(int i=0;i<v[top].size();i++)
        {
                ck=true;
                int asus=v[top][i];
                ///cout<<"asus ="<<asus<<endl;
                if(seen[asus]==0 && asus!=x)
                {
                    seen[asus]=seen[top]+1;
                    ///if(bapke[asus]==-1)bapke[asus]=top;
                    ans[seen[top]]++;
                   /// cout<<"dis = "<<seen[asus]<<endl;
                    if(ans[seen[top]]>maxi){
                        maxi=ans[seen[top]];
                        ///cout<<"maxi "<<maxi<<endl;
                        pos=seen[asus];
                        ///cout<<"mx = "<<maxi<<" "<<pos<<endl;
                    }
                    bapke[asus]=seen[asus];
                    q.push(asus);
                    ///cout<<"asus "<<asus<<endl;
                }
        }
        q.pop();
    }
}
int main()
{
    int e,t,q,x, y;
    cin>>e;
    for(int i=0;i<e;i++){
        cin>>q;
        for(int j=0;j<q;j++){
            cin>>x;
            v[i].push_back(x);
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>y;
        bfs(y);
        if(ck==false)cout<<0<<endl;
        else
            cout<<maxi<<" "<<pos<<endl;
    }
    return 0;
}
