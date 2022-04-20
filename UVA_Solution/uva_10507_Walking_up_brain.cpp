#include <bits/stdc++.h>
#define ll long long
using namespace std;
bitset<30>b;
int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&m);
        char x[5];
        scanf("%s",x);
        vector<int>v[30];
        b.reset();
        for(int i=0;i<3;i++)b.set(x[i]-'A');
        for(int i=0;i<m;i++){
            scanf("%s",x);
            v[x[0]-'A'].push_back(x[1]-'A');
            v[x[1]-'A'].push_back(x[0]-'A');

        }
        int Y=0;
        while(b.count()<n)
        {
            vector<int>NonSleeper;
            for(int i=0;i<26;i++)
            {
               if(b[i])continue;
               int sz=v[i].size();
               int asepashe=0;
               for(int j=0;j<sz;j++){
                  if(b[v[i][j]])asepashe++;
               }
               if(asepashe>=3)NonSleeper.emplace_back(i);
            }
            int sz=NonSleeper.size();
            if(!sz)break;
            for(int i=0;i<sz;i++)b.set(NonSleeper[i]);
            Y++;

        }
        if(b.count()!=n)printf("THIS BRAIN NEVER WAKES UP\n");
        else printf("WAKE UP IN, %d, YEARS\n",Y);
    }
    return 0;

}
