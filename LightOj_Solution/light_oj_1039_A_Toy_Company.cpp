#include <bits/stdc++.h>
#define mx 1000000
using namespace std;
struct data
{
    string x;
    int cnt;
};

int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
        string x,e,f,g,y1;
        map<string,bool>seen;

        int ans=0;
        cin>>x>>y1;
        int q1;
        cin>>q1;
        for(int u=0; u<q1; u++)
        {
            cin>>e>>f>>g;
            int L1=e.size(),L2=f.size(),L3=g.size();
            for(int i=0; i<L1; i++)
                for(int j=0; j<L2; j++)
                    for(int k=0; k<L3; k++)
                    {
                        string M;
                        M+=e[i];
                        M+=f[j];
                        M+=g[k];
                        seen[M]=1;
                    }
        }
        cout<<"Case "<<a<<": ";
        bool ck=false;
        if(seen[x]==1 || seen[y1]==1)cout<<"-1"<<endl;
        else if(x==y1)cout<<"0"<<endl;
        else{

            queue<data>q;
            q.push({x,0});
            while(!q.empty()){

            string x1,x2,x3,x4,x5,x6,asus=q.front().x;
            int dis=q.front().cnt;
            x1=asus,x2=asus,x3=asus,x4=asus,x5=asus,x6=asus;

            if(x1[0]=='a')x1[0]='z';
            else x1[0]=(int)x1[0]-1;
            if(x2[0]=='z')x2[0]='a';
            else x2[0]=(int)x2[0]+1;

            if(x3[1]=='a')x3[1]='z';
            else x3[1]=(int)x3[1]-1;
            if(x4[1]=='z')x4[1]='a';
            else x4[1]=(int)x4[1]+1;

            if(x5[2]=='a')x5[2]='z';
            else x5[2]=(int)x5[2]-1;
            if(x6[2]=='z')x6[2]='a';
            else x6[2]=(int)x6[2]+1;

             if(x1==y1 || x2==y1 || x3==y1 || x4==y1 || x5==y1 || x6==y1){
                cout<<dis+1<<endl;ck=true;break;
             }
             else
             {
                 if(seen[x1]==0){q.push({x1,dis+1}),seen[x1]=1;}
                 if(seen[x2]==0){q.push({x2,dis+1}),seen[x2]=1;}
                 if(seen[x3]==0){q.push({x3,dis+1}),seen[x3]=1;}
                 if(seen[x4]==0){q.push({x4,dis+1}),seen[x4]=1;}
                 if(seen[x5]==0){q.push({x5,dis+1}),seen[x5]=1;}
                 if(seen[x6]==0){q.push({x6,dis+1}),seen[x6]=1;}

             }
             if(ck)break;
             q.pop();


            }
            if(!ck)cout<<"-1"<<endl;

        }
    }
    return 0;
}
