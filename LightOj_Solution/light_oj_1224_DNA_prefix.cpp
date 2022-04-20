#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll maxi=0,cnt=0;
int seen[150],pre;
struct data
{
    data *next[4]={NULL};
    int counting=0;
};
data *node=NULL;
/*bool comp(ok u,ok u1)
{
    if(u.len!=u1.len)return u.len<u1.len;
    return u.z<u1.z;
}*/
void go(string x)
{
    ll len=x.size();
    maxi=max(maxi,len);
    bool ck=false;
    data *start=NULL;
    start=node;
    for(int i=0;i<len;i++){
        int num=seen[x[i]];
        //cout<<"num = "<<num<<endl;
        if(start->next[num]==NULL){
            start->next[num]=new data();
        }
        /*else {
                //if(i+1<=pre)
                maxi=max(maxi,((i+1)*cnt));
        }*/
        start->next[num]->counting++;
        ll val=(i+1)*start->next[num]->counting;
        maxi=max(maxi,val);
        //cout<<"cnt= "<<(i+1)*cnt<<endl;
        //cout<<"maxi = "<<maxi<<endl;
        start=start->next[num];
    }
}
void all(data *start)
{
    for(int i=0;i<4;i++){
        if(start->next[i])all(start->next[i]);
    }
    delete(start);
}
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        int n;cin>>n;
        node=new data();
        seen['A']=0,seen['C']=1,seen['G']=2,seen['T']=3;
        maxi=0;
        string x,y;
        //vector<string>v;
        for(int i=0;i<n;i++){
            cin>>x;//v.push_back(x);
            go(x);
        }
        //sort(v.begin(),v.end(),greater<string>());
        //int olala=v[0]
         cnt=0;
         pre=10000000;
        /*for(int i=0;i<n;i++){
            //cout<<"x= "<<x<<endl;
            x=v[i];
            cnt++;
            //if(v[i].len==olala)cnt++;
            //else cnt=1;
            //cout<<"x= "<<x<<endl;
            go(x);
            //pre=v[i].len;
        }*/
        cout<<"Case "<<a<<": "<<maxi<<endl;
        all(node);
    }
    return 0;
}
