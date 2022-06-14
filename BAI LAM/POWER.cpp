#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll a,ll n,ll m)
{
    int ans=1;
    while(n)
    {
        if(n%2)ans=(ans*a)%m;
        a=(a*a)%m;
        n>>=1;
    }
    return ans;
}

ll a,n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("power.inp","r",stdin);
    //freopen("power.out","w",stdout);

    cin>>a>>n>>m;
    cout<<power(a,n,m);

}
