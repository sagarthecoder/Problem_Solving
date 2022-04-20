#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ara[200];
int main()
{
    string x;
    ara['A']=2,ara['B']=2,ara['C']=2;
    ara['D']=3,ara['E']=3,ara['F']=3;
    ara['G']=4,ara['H']=4,ara['I']=4;
    ara['J']=5,ara['K']=5,ara['L']=5;
    ara['M']=6,ara['N']=6,ara['O']=6;
    ara['P']=7,ara['Q']=7,ara['R']=7,ara['S']=7;
    ara['T']=8,ara['U']=8,ara['V']=8;
    ara['W']=9,ara['X']=9,ara['Y']=9;
    ara['Z']=9;

    while(cin>>x)
    {
        int len=x.size();
        for(int i=0;i<len;i++){
            if(x[i]=='-' || x[i]=='0' || x[i]=='1')
                cout<<x[i];
            else cout<<ara[x[i]];
        }
        cout<<endl;
    }
    return 0;
}
