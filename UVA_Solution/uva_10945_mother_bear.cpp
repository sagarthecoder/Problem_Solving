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
int main()
{
    string x,y,z;
    while(true)
    {
        getline(cin,x);
        if(x=="DONE")break;
        int len=x.size();
        for(int i=0;i<len;i++)
        {
            x[i]=tolower(x[i]);
            if(x[i]>='a' && x[i]<='z')y+=x[i];
        }
        len=y.size();
        for(int i=len-1;i>=0;i--)z+=y[i];
        if(y==z)cout<<"You won't be eaten!"<<endl;
        else
            cout<<"Uh oh.."<<endl;
        y.clear();
        z.clear();
    }
    return 0;
}
