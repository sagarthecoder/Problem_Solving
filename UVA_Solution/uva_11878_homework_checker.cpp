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
int main()
{
    int a,ans=0;
    while(cin>>a)
    {
        char ch1,ch2;
        int b,res,taken;
        string x;
        cin>>ch1;
        cin>>b;
        cin>>ch2;
        cin>>x;
        ///cout<<a<<" "<<ch1<<" "<<b<<" "<<ch2<<" "<<x<<endl;
        if(ch1=='+')b=a+b;
        if(ch1=='-')b=a-b;
       ///out<<" b af = "<<b<<endl;
        if(x!="?")
        {
            for(int i=0;i<x.size();i++)
            {
                if(i==0)taken=x[i]-'0';
                else
                    taken=(taken*10)+(x[i]-'0');
            }
            if(taken==b)ans++;
            ///cout<<"taken ="<<taken<<endl;
        }
    }
    cout<<ans<<endl;
}
