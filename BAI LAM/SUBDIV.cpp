//2021-07-05
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=1e3+3;

ll n,k,f[M][M],a[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("subdiv.inp","r",stdin);
    freopen("subdiv.out","w",stdout);

    for(int i=0;i<M;i++)
    fill(f[i],f[i]+M,-1);
    f[0][0]=0;

    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]<0)
        {
            a[i]=-(abs(a[i])%k)+k;
        }
    }

    for(int j=1; j<=n; j++)
        for(int i=0; i<=k; i++)
        {
            if(f[j-1][i]>-1)
            {
                f[j][(i+a[j])%k]=max(f[j-1][i]+1,f[j][(i+a[j])%k]);
                f[j][i]=max(f[j][i],f[j-1][i]);
            }
        }
    cout<<n-f[n][0];
}
