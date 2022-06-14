#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=1e6+10;

int f[M];
ll a,b,t,d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("DIVCNT.inp","r",stdin);
    freopen("DIVCNT.out","w",stdout);

    cin>>a>>b;

    for(ll i=2;i<=sqrt(b);i++)
        for(ll j=int((a+i-1)/i)*i;j<=b;j+=i)
            if(i<=sqrt(j))f[j-a]++;


    for(ll i=0;i<=b-a;i++)f[i]=f[i]*2+2;

    for(ll i=0;i<=b-a;i++)
        if(ll(sqrt(i+a))*ll(sqrt(i+a))==i+a)f[i]--;


    for(ll i=0;i<=b-a;i++)if(f[t]<f[i])t=i;
    cout<<f[t]<<" "<<t+a<<" ";

    for(ll i=0;i<=b-a;i++)if(f[i]==f[t])d++;
    cout<<d;
}
