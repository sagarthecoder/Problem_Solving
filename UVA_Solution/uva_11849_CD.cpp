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
int main()
{
    int m,n;
    while(true)
    {

        cin>>m>>n;if(m==0 && n==0)break;
        int cnt=0;
        ///if(m==0 || n==0)cout<<0<<endl;
        //else{
        set<int>s;
        int x;
        set<int>:: iterator it;
        for(int i=0;i<m;i++){
           cin>>x ;
           s.insert(x);
        }
        int sz=s.size();
        for(int i=0;i<n;i++){
            cin>>x;
            s.insert(x);
            if(s.size()==sz)cnt++;
            sz=s.size();
        //}
    }
    cout<<cnt<<endl;
   }
   return 0;
}
