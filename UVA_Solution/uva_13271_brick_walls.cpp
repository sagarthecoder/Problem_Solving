#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b,c,d;
    while(true)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if(a+b+c+d==0)break;
        if(a<c){
            swap(a,c);swap(b,d);
        }
        ll ans=(abs(c-a))*2;ll col=abs(a-c);
        if(a%2==0 && b%2!=0){ans--;
        col--;
        }
        else if(a%2!=0 && b%2==0){ans--;
        col--;
        }
        //cout<<"ansUp ="<<ans<<endl;
        //cout<<"col = "<<col<<endl;
        if(abs(b-d)>col){
            ans+=(abs(d-b)-col);
        }
        else if(c%2==0 && d%2!=0)ans++;
        else if(c%2!=0 && d%2==0)ans++;
        printf("%lld\n",ans);

    }
    return 0;
}
