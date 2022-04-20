#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string x;
    while(getline(cin,x))
    {
        int len=x.size();
        for(int i=0;i<len;i++)
        {
            //int n=((int)x[i])-7;
            //cout<<(char)n;
            cout<<(char)(x[i]-7);
        }
        cout<<endl;
    }
    return 0;
}
