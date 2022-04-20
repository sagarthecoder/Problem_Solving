#include<cstdio>
#include<sstream>
#include<cstdlib>
#include <iomanip>
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
#define ll long long
#define sf scanf
#define pf printf
#define pb push_back
using namespace std;
struct data
{
    int temp;
    data *next[27]= {NULL};

};
data *root;
void go(string x)
{
    data *now=root;
    int len=x.size(),num;
    for(int i=0; i<len; i++)
    {
        num=x[i]-'a';
        if(now->next[num]==NULL)now->next[num]=new data();
        now=now->next[num];
        now->temp++;
    }
}
int ans(string x)
{
    data *now=root;
    int len=x.size(),num;
    int z=0;
    for(int i=0; i<len; i++)
    {
        num=x[i]-'a';
        z++;
        now=now->next[num];
        if(now->temp==1)break;
    }
    return z;
}
void del(data *now)
{
    for(int i=0; i<26; i++)
        if(now->next[i])del(now->next[i]);
    delete(now);
}
int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
        string x;
        root=new data();
        vector<string>v;
        vector<string>v2;
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
          cin>>x;
          v.push_back(x);
        }
        v2=v;
        sort(v.begin(),v.end());
        int sz=n;
        for(int i=0; i<sz; i++)
        {
            go(v[i]);
        }
        int ok=0;
        for(int i=0; i<sz; i++)
        {
            ok+=ans(v2[i]);
        }
        cout<<ok<<endl;
        del(root);

    }
    return 0;
}
