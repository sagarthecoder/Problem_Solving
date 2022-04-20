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
    int n;
    string x;
    while(cin>>n>>x){
    map<string,int>seen;
    string z,y;
    int maxi=0,j;
    for(int i=0;i<=x.size()-n;i++)
    {
        y.clear();
        for( j=i;j<i+n;j++){
           y+=x[j];
        }
        if(!y.empty())seen[y]++;
        if(seen[y]>maxi){
            z=y;
            maxi=seen[y];
        }
        for(int k=j;k<n;k++){
            y[n-1]=x[k];
            seen[y]++;
           if(seen[y]>maxi)
            z=y;
            maxi=seen[y];
        }
    }
    cout<<z<<endl;
    ///cout<<seen[z]<<endl;
    seen.clear();
   }
   return 0;
}
