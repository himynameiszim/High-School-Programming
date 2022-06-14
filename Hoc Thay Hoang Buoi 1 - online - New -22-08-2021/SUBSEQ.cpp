#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll llinf=1e18+18;
const int M=1e6+6;

int a[M],n,k;
ll b[M],c[M],ans=-llinf;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("SUBSEQ.inp","r",stdin);
    freopen("SUBSEQ.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i],b[i]=a[i]+b[i-1];
        c[i]=min(b[i],c[i-1]);
    }
    for(int i=k;i<=n;i++)
    {
        ans=max(b[i]-c[i-k],ans);
    }
    cout<<ans;
}
