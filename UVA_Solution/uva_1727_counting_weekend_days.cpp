#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<string>v;
int main()
{
    v.push_back("SUN");
    v.push_back("MON");
    v.push_back("TUE");
    v.push_back("WED");
    v.push_back("THU");
    v.push_back("FRI");
    v.push_back("SAT");
    int i=0;
    int t;cin>>t;
    while(t--)
    {
        string x,y;cin>>x>>y;
        int date=30;
        int cnt=0;
        if(x=="JAN" || x=="MAR" || x=="MAY" || x=="JUL" || x=="AUG" || x=="OCT" || x=="DEC")date=31;
        else if(x=="FEB")date=28;
        bool ck=false;
        int ans=0;
        while(cnt<date)
        {
            if(i==7)i=0;
            if(v[i]==y && ck==false){
                ck=true;
            }
            if(ck)cnt++;
            if(ck==true){
                if(v[i]=="FRI" || v[i]=="SAT")ans++;
            }
            i++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
