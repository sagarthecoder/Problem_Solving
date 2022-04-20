#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<long long int>sagar;
void ck()
{
    sagar.push_back(2);
    sagar.push_back(3);
    sagar.push_back(5);
    sagar.push_back(7);
    sagar.push_back(11);
    sagar.push_back(13);
    sagar.push_back(17);
    sagar.push_back(31);
    sagar.push_back(37);
    sagar.push_back(71);
    sagar.push_back(73);
    sagar.push_back(79);
    sagar.push_back(97);
    sagar.push_back(113);
    sagar.push_back(131);
    sagar.push_back(199);
    sagar.push_back(311);
    sagar.push_back(337);
    sagar.push_back(373);
    sagar.push_back(733);
    sagar.push_back(919);
    sagar.push_back(991);

}
int main()
{
    long long int n,res,m,i,take;
    ck();
    while(1)
    {
        cin>>n;
        take=n;
        res=0;
        if(n==0)
            break;
        if(n>991)
            cout<<0<<endl;
        else
        {
            while(1)
            {
                m=n%10;
                res=res+1;
                n=n/10;
                if(n==0)
                {
                    res=pow(10,res);
                    break;
                }
            }
            for(i=0; i<sagar.size(); i++)
            {
                if(sagar[i]>take)
                {
                    if(sagar[i]<res)
                        cout<<sagar[i]<<endl;
                    else
                        cout<<0<<endl;
                        break;
                }
            }
        }

    }
    return 0;
}
