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
using namespace std;
#define ll long long int
struct data
{
    char ch;
    int num;
};
/*map<char,int>seen;
vector<char>v;
vector<data>v1;*/
bool comp(data e,data f)
{
    //if(e.num<f.num)return e.num>f.num;
     if(e.num==f.num)
        return e.ch<f.ch;
      else
        return e.num>f.num;
    //else
    //return e.num<f.num;
}
int main()
{


    int n;
    string x;
    while(cin>>n)
    {
        getline(cin,x);
        map<char,int>seen;
        vector<char>v;
        vector<data>v1;
        for(int a=0; a<n; a++)
        {
            getline(cin,x);
            int len=x.size();
            for(int i=0; i<len; i++)
            {
                x[i]=toupper(x[i]);
                if(x[i]>='A' && x[i]<='Z')
                {
                    if(seen[x[i]]==0)
                        v.push_back(x[i]);
                    seen[x[i]]++;
                }
            }
        }
        //sort(v.begin(),v.end(),comp);
        for(int i=0; i<v.size(); i++)
        {
            data sir;
            sir.ch=v[i];
            sir.num=seen[v[i]];
            //v1.push_back({v[i],seen[v[i]]});
            v1.push_back(sir);
        }
        // bool ck=false;
        sort(v1.begin(),v1.end(),comp);
        for(int i=0; i<v1.size(); i++)
        {
            // if(ck==true)cout<<endl;
            cout<<v1[i].ch<<" "<<v1[i].num<<endl;
            //printf("%c %d\n",v1[i].ch,v1[i].num);
            //ck=true;
        }
        //v.clear();
        //v1.clear();
        //seen.clear();
    }

    return 0;
}
