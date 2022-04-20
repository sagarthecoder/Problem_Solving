#include <bits/stdc++.h>
#define ll long long
using namespace std;
int abc[1002][26],rev[1002][26];
char x[1004];
int main()
{
    int t;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%s",x);
        int len=strlen(x);memset(abc,0,sizeof(abc));
        memset(rev,0,sizeof(rev));
        for(int i=1,j=len;i<=len;i++,j--)
        {
             int ch=x[i-1]-'a';
             int ch2=x[j-1]-'a';
            for(int k=0;k<26;k++){

                    if(ch==k)
                    abc[i][ch]=abc[i-1][ch]+1;
                    else abc[i][k]=abc[i-1][k];

                    if(ch2==k)
                    rev[j][ch2]=rev[j+1][ch2]+1;
                    else rev[j][k]=rev[j+1][k];
            }
        }
        ll sum=0;
        for(int i=1;i<=len;i++)
        {

            for(int j=i;j<=len;j++)
            {
                int odd=0;
                for(int k=0;k<26;k++){
                    int bad=abc[len][k]-abc[i-1][k]-rev[j+1][k];
                    if(bad%2!=0)odd++;
                }
                if(odd<=1)sum++;
            }
        }
        printf("Case %d: %lld\n",a,sum);
    }
    return 0;
}

