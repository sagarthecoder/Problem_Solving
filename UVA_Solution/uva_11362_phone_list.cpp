#include <bits/stdc++.h>
using namespace std;
struct data
{
    int endMark=false;
    data *next[10]={NULL};
};
bool ck;
data *root;
void go(string x)
{
    int len=x.size(),num;
    data *now=root;
    for(int i=0;i<len;i++){
        num=x[i]-'0';
        if(now->endMark==true){
            ck=true;
            break;
        }
        if(now->next[num]==NULL)now->next[num]=new data();
        now=now->next[num];
    }
    if(now->endMark==true)ck=true;
    now->endMark=true;
}
void del(data *now)
{
    for(int i=0;i<10;i++)
        if(now->next[i])del(now->next[i]);
    delete(now);
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        ck=false;string x;
        root=new data();
        int n;cin>>n;
        vector<string>v;
        for(int i=0;i<n;i++){
            cin>>x;v.push_back(x);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
             x=v[i];
            if(ck==false)go(x);
            ///cout<<"ck = "<<ck<<endl;
        }
        if(ck)cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
         del(root);
    }
    return 0;
}
