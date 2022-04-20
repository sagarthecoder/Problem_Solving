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
map<string,string>bap;
map<string,bool>seen;
map<string,int>cnt;
string bapke(string x)
{
    if(bap[x]==x)return x;
    return bap[x]=bapke(bap[x]);
}
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        int n;cin>>n;
        //if(bap["sds"]==)cout<<"ddfd"<<endl;
        for(int i=0;i<n;i++)
        {
            string x ,y;cin>>x>>y;
            if(x<y)swap(x,y);
            if(seen[x]==false){bap[x]=x;seen[x]=true;}
            if(seen[y]==false){bap[y]=y;seen[y]=true;}
            string A=bapke(x);
            string B=bapke(y);
            ///cout<<"A= "<<A<<"  , B = "<<B<<endl;
            if(A==B){
                    if(cnt[A]==0)cout<<1<<endl;
                    else
                    cout<<cnt[A]<<endl;
            }
            else{
                bap[B]=A;
                if(cnt[A]==0 && cnt[B]==0){cnt[A]++;
                 cnt[B]++;
                }
                else if(cnt[A]==0)cnt[A]++;
                else if(cnt[B]==0) cnt[B]++;
                cout<<cnt[A]+cnt[B]<<endl;
                cnt[A]=cnt[A]+cnt[B];
            }
        }
        cnt.clear();bap.clear();seen.clear();
    }
    return 0;
}
