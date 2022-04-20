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
int main()
{
    string s;
    while(true){
    cin>>s;
    if(s=="#")break;
    bool val = next_permutation(s.begin(), s.end());
    if (val == false)
        cout << "No Successor" << endl;
    else
        cout <<s<< endl;
    }
    return 0;
}
