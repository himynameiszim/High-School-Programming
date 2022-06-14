#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m,n,k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("LARES.inp","r",stdin);
    freopen("LARES.out","w",stdout);

    cin>>m>>n>>k;
    ll l=0,r=1e9;
    while(r-l>1)
    {
        ll M=(l+r)/2;
        if(m>=M*2&&n>=M&&m-M*2+n-M>=k)l=M;
        else r=M;
    }
    cout<<l;

}
