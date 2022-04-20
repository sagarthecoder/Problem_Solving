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
    int n,sz;
    vector<int>L;
    while(cin>>n)
    {
        L.push_back(n);
        sz=L.size();
        for(int i=0;i<sz;i++)
        {
            //int *x=&L.end()-1;
            if((L[i])>n)swap(L[i],L[sz-1]);
        }
        if(sz%2==0)cout<<(L[sz/2]+L[sz/2-1])/2<<endl;
        else
            cout<<L[sz/2]<<endl;
        //for()
    }
    return 0;
}
