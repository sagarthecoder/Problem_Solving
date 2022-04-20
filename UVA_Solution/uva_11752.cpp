#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#define big 18446744073709551615
using namespace std;
vector<long long int>sagar;
int main()
{
    long long int nahid,res,i,j;
    for(i=16;i<=big;)
    {
        sagar.push_back(i);
        i*=4;
    }
    for(i=81;i<=big)
    {
        sagar.push_back(i);
        i*=9;
    }
}
