
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
#define mx 10000005
#define mod 100000007
#define inf 0x3f3f3f3f3f3f3f
map<char,int>seen;
vector<char>sagar[100];
vector<char>taken;
map<char,int>seen2;
void dfs(char a)
{
    if(seen[a])return;
    seen[a]=1;
    for(int i=0; i<sagar[a].size(); i++)
    {
        dfs(sagar[a][i]);
    }
}
int main()
{
    int t,res,cnt,to;
    char  x;
    cin>>t;
    while(t--)
    {

        cnt=0;
        to=0;
        cin>>x;

        int sz=(x);
        res=0;
        string y;
        getline(cin,y);
        while(1)
        {
            getline(cin,y);
            if(y.empty()==true)break;
            char ch=y[0];
            if(seen2[ch]==0)
            {
                taken.push_back(ch);
                seen2[ch]=1;
                cnt++;
            }
            char ch2=y[1];
            if(seen2[ch2]==0)
            {
                taken.push_back(ch2);
                seen2[ch2]=1;
                cnt++;
            }
            sagar[ch].push_back(ch2);
            sagar[ch2].push_back(ch);
        }
        for(int i=0; i<taken.size(); i++)
        {
            char a=taken[i];
            if(seen[a]==0)
            {
                dfs(a);
                seen[a]=1;
                res++;
            }
        }
        to=(sz)-(64+cnt);
        seen.clear();
        taken.clear();
        seen2.clear();
        for(int i=65;i<=sz;i++){
            char c=char(i);
            sagar[c].clear();
        }
        cout<<res+to<<endl;
        if(t)
        cout<<endl;




    }
    return 0;

}
