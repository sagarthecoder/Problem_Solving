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
vector<string>v;
int main()
{
    string x;
    while(cin>>x)
    {
        int len=x.size();
        string y,z;
        for(int i=0; i<len; i++)
        {
            if(x[i]=='[')
            {
                i++;
                while(x[i]!=']' && i<len)
                {
                    if(x[i]=='[')
                    {
                        if(y.size()!=0)v.push_back(y);
                        y.clear();
                    }
                    else
                        y+=x[i];
                    i++;
                }
                if(y.size()!=0)v.push_back(y);
                y.clear();
            }
            else
            {
                if(x[i]!=']')z+=x[i];
            }
        }
        for(int i=v.size()-1; i>=0; i--)cout<<v[i];
        cout<<z<<endl;
        v.clear();
        z.clear();
    }
    return 0;
}
