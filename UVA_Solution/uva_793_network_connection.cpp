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
#include <unordered_map>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define ll long long int
int bapke[100000];
int bapke_find(int x,int y)
{
    while(1)
    {
        if(bapke[x]==x){
            bapke[y]=x;
            break;
        }
        x=bapke[x];

    }
    return x;
}
int main()
{
    int t;
    string x;
    cin>>t;
    for(int a=1;a<=t;a++)
    {
        int n,joy=0,porajoy=0;
        cin>>n;
        getline(cin,x);
        for(int i=0;i<=n;i++)bapke[i]=i;
        char ch;
        int u,v;
        while(true){
            getline(cin,x);
            int m,m1;
            if(x.empty())break;
            ch=x[0];
            for(m=2; ; m++)
            {
                if(x[m]==' ')break;
                if(m==2)u=x[m]-'0';
                else
                    u=(u*10)+(x[m]-'0');
            }
            for(m1=m+1;m1<x.size();m1++)
            {
                if(m1==m+1)v=x[m1]-'0';
                else
                    v=(v*10)+(x[m1]-'0');
            }
            if(u>v)swap(u,v);
            if(ch=='c'){
                   u=bapke_find(u,u);
                v=bapke_find(v,v);
                if(u!=v){
                     bapke[v]=u;
                   }
            }
            else
            {
               int ans1=bapke_find(bapke[u],u);
               int ans2= bapke[v]=bapke_find(bapke[v],v);
               if(ans1==ans2)joy++;
               else
                   porajoy++;
            }
        }
        cout<<joy<<","<<porajoy<<endl;
        if(a!=t)cout<<endl;

    }
    return 0;
}
