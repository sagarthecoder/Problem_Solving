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
int main()
{
    string x,y;
    while(getline(cin,x))
    {
       getline(cin,y);
       map<char,int>seen;
       map<char,int>seen2;
       set<char>s;
       set<char>:: iterator it;
       int len1=x.size();
       int len2=y.size();
       for(int i=0;i<len1;i++)seen[x[i]]++;
       for(int i=0;i<len2;i++){
            if(seen[y[i]]>0)s.insert(y[i]);
            seen2[y[i]]++;
       }
       for(it=s.begin();it!=s.end();it++){
        char ch=*it;
        int mx=min(seen[ch],seen2[ch]);
        for(int i=0;i<mx;i++)cout<<ch;
       }
       cout<<endl;

    }
    return 0;
}
