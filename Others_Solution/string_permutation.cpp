#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string big,small;cin>>big>>small;
    int len=big.size();
    int CharSum[len+1][26]={0};
    int TotalFromSmall[26]={0};
    int cnt[26]={0};
    int first[26];
    vector<int>v[26];
    int ans=0;
    memset(first,-1,sizeof(first));
    for(int i=0;i<len;i++)
    {
        int temp=big[i]-'a';
        for(int j=0;j<26;j++){
            if(i==0){
                if(j==temp)CharSum[i][j]=1;
            }
            else {
                if(j==temp)CharSum[i][j]=CharSum[i-1][j]+1;
                else CharSum[i][j]=CharSum[i-1][j];
            }
        }
    }

    for(int i=0;i<small.size();i++){
        TotalFromSmall[small[i]-'a']++;
    }

    for(int i=0;i<len;i++)
    {
        int temp=big[i]-'a';
        v[temp].push_back(i);
        cnt[temp]++;
        if(cnt[temp]==1)first[temp]=i;
        if(cnt[temp]>TotalFromSmall[temp]){
            for(int j=0;j<26;j++)
            {
                if(v[j].empty() or  first[j]==-1){
                    first[j]=-1,cnt[j]=0;continue;
                }
                int upper=upper_bound(v[j].begin(),v[j].end(),first[temp])-v[j].begin();
                if(upper==v[j].size()){
                    first[j]=-1;
                    cnt[j]=0;
                }
                else{
                    first[j]=v[j][upper];
                    cnt[j]=CharSum[i][j]-CharSum[v[j][upper-1]][j];
                }
            }
        }
        bool ck=false;
        for(int j=0;j<26;j++){
            if(cnt[j]!=TotalFromSmall[j]){
                ck=true;break;
            }
        }
        if(!ck){
            cout<<"start = "<<i-small.size()+1<<" , finish = "<<i<<endl;
            ans++;
        }
    }
    cout<<"total = "<<ans<<endl;
    /*
    ababababkbab
    aba
    */

}
