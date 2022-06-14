//Thầy Hoàng
//Difference Array
//AC
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod=1e9;
const int M=1e5+5;

ll a[M],d[M],l,r,n,m,q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("udtseq2.inp","r",stdin);
    freopen("udtseq2.out","w",stdout);

    cin>>n>>q;
    for(int i=0;i<q;i++)
    {
        cin>>l>>r>>m;
        d[l]+=m;
        d[r+1]+=-m*(r-l+2);
        d[r+2]+=m*(r-l+1);
    }

    for(int i=1;i<=n;i++)
    {
        d[i]+=d[i-1];
        a[i]=+a[i-1]+d[i];
        if(a[i]>=0)a[i]%=mod;
        else a[i]=-(abs(a[i])%mod)+mod;
        cout<<a[i]<<" ";
    }
}
