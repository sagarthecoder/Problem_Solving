#include <bits/stdc++.h>
#define ll long long
using namespace std;
char x[45];
int seen[100];
char they[40][20][48];
int main()
{


    int n,q;
    scanf("%d %d",&n,&q);
    scanf("%s",x);
    int len=strlen(x);
    for(int i=0; i<len; i++)
    {
        seen[x[i]]=i;

    }
    //getchar();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<17; j++)
            scanf("%s",they[i][j]);
    }
    int cnt[19][44],bosaw[19][48]= {0};
    for(int a=1; a<=q; a++)
    {
        scanf("%s",x);
        len=strlen(x);
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<len; i++)
        {
            int pos=seen[x[i]];
            for(int j=0; j<16; j++)
            {
                for(int k=0; k<43; k++)
                {
                    if(they[pos][j][k]=='*')
                    {
                        cnt[j][k]++;
                        bosaw[j][k]=i;
                    }
                }
            }
        }
        int ans[len+2]= {0};
        for(int i=0; i<16; i++)
        {
            for(int j=0; j<43; j++)
            {
                if(cnt[i][j]==1)
                    ans[bosaw[i][j]]=1;
            }
        }
        printf("Query %d: ",a);
        for(int i=0; i<len; i++)
        {
            if(ans[i])
                printf("Y");
            else
                printf("N");
        }
        printf("\n");

    }
    return 0;



}
