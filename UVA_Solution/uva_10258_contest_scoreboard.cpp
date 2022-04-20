#include <bits/stdc++.h>
using namespace std;
struct data
{
    int a,solved,time;
}ara[110];
int ara2[110][18];
bool seen[110];
bool BAL[110][18];
vector<int>v;
vector<data>ok;
bool comp(data u,data u1)
{
    if(u.solved==u1.solved && u.time==u1.time)return u.a<u1.a;
    if(u.solved==u1.solved)return u.time<u1.time;
    return u.solved>u1.solved;
}
int main()
{
    int t,n;cin>>t;
    string x;getline(cin,x);
    getline(cin,x);

    for(int a=1;a<=t;a++)
    {
        while(true)
        {
            getline(cin,x);
            int len=x.size();
            if(len==0)break;
            int A,B,C,i,j,k;
            char ch;
            for(i=0; ;i++){
                if(x[i]==' ')break;
                if(i==0)A=x[i]-'0';
                else
                    A=(A*10)+(x[i]-'0');

            }
            for(j=i+1; ;j++){
                if(x[j]==' ')break;
                if(j==i+1)B=x[j]-'0';
                else B=(B*10)+(x[j]-'0');
            }
            for(k=j+1; ;k++){
                if(x[k]==' ')break;
                if(k==j+1)C=x[k]-'0';
                else C=(C*10)+(x[k]-'0');
            }
            ch=x[len-1];
            if(seen[A]==0){v.push_back(A);
            seen[A]=true;
            }
            if(ch=='C' && BAL[A][B]==0){
                ara[A].solved++;
                //cout<<"olala = "<<ara2[A].T<<endl;
                ara[A].time+=(C+ara2[A][B]);
                BAL[A][B]=1;
                ara2[A][B]=0;

            }
            if(ch=='I')ara2[A][B]+=20;
        }
        int sz=v.size();
        for(int i=0;i<sz;i++){
            int asus=v[i];
            ok.push_back({asus,ara[asus].solved,ara[asus].time});
        }
        sort(ok.begin(),ok.end(),comp);
        for(int i=0;i<sz;i++)
        {
            cout<<ok[i].a<<" "<<ok[i].solved<<" "<<ok[i].time<<endl;
        }
        if(a!=t)cout<<endl;
        v.clear();
        ok.clear();
        ///memset(ara,0,sizeof(int));
        memset(seen,0,sizeof(seen));
        memset(BAL,0,sizeof(BAL));
        memset(ara2,0,sizeof(ara2));
        memset(ara,0,sizeof(ara));
    }
    return 0;
}
