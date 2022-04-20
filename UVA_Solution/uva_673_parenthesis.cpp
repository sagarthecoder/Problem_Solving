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
int main()
{
    int t;
    cin>>t;
    string x;
    getline(cin,x);
    for(int a=1;a<=t;a++)
    {
        getline(cin,x);
        stack<char>s;
        int len=x.size();
        if(len==0)cout<<"Yes"<<endl;
        else{
        bool ck=true;
        for(int i=0;i<len;i++)
        {
            //cout<<"size:= "<<s.size()<<endl;
            if(x[i]==')')
            {
               // cout<<"size:= "<<s.size()<<endl;
                if(s.size()>0 && s.top()=='(')s.pop();
                else
                {
                    ck=false;
                    break;
                }
            }
            else if(x[i]=='}')
            {
                if(s.size()>0 && s.top()=='{')s.pop();
                else
                {
                    ck=false;
                    break;
                }
            }
            else if(x[i]==']')
            {
                if(s.size()>0 && s.top()=='[')s.pop();
                else
                {
                    ck=false;
                    break;
                }
            }
            else if(x[i]=='(' || x[i]=='{' || x[i]=='[')
                s.push(x[i]);
        }
        if(ck==false || s.size()>0)cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    }
    return 0;
}
