#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=1e5+5;

ll a[M],n,ans,sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("GRAVELs.inp","r",stdin);
    freopen("GRAVELs.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    sum/=n;
    for(int i=1;i<=n;i++)
    {
        a[i+1]-=sum-a[i];
        ans+=abs(sum-a[i]);
    }
    cout<<ans;
}
