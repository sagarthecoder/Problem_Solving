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
#define ll unsigned long long
#define sf scanf
#define pf printf
#define pb push_back
using namespace std;
int main()
{
    while(true){
    ll L,R;scanf("%llu %llu",&L,&R);
    if(!L && !R)break;
    ll two=(R/5)+1;
    ll one=((L-1)/5)+1;
    if(((L/5)+1)==one)one--;
    ll ans=two-one;
    printf("%llu\n",ans);
    }
    return 0;
}
