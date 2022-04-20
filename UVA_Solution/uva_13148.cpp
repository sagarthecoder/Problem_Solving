#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    while(1){
    cin>>n;
    if(n==0)break;
    double sq=sqrt(n);
    int n1=ceil(sq);
    int n2=floor(sq);
    int ck=0;
    int j=1;
    while(1)
    {
        int ans=j*j*j;
        if(ans==n)ck=1;
        if(ans>=n)break;
        j++;
    }
    if(ck==1 && n1==n2)cout<<"Special"<<endl;
    else
        cout<<"Ordinary"<<endl;
    }
    return 0;
}
