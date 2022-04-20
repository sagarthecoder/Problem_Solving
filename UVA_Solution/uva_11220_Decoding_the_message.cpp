#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    string x;
    getline(cin,x);
    getline(cin,x);
    for(int a=1; a<=t; a++)
    {
        cout<<"Case #"<<a<<":"<<endl;

        while(true)
        {
            getline(cin,x);
            int len=x.size();
            if(!len)
                break;
            int ok=1;
            string y="";
            for(int i=0; i<len; i++)
            {
                if(x[i]==' ')
                {
                    int sz=y.size();
                    if(sz>=ok)
                    {
                        cout<<y[ok-1];
                        ok++;
                    }
                    y="";
                    ///cout<<x[i];
                }
                else
                    y+=x[i];
            }
            int sz=y.size();
            if(sz>=ok)
            {
                cout<<y[ok-1];
                ok++;
            }
            cout<<endl;
        }
        if(a!=t)cout<<endl;
    }
    return 0;
}
