#include<bits/stdc++.h>

using namespace std;

const int M=1e3+3;

int a[M][M],b[M][M],c[M][M],n,ans,k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("bonus.inp","r",stdin);
    freopen("bonus.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)cin>>a[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            b[i][j]=b[i-1][j]+a[i][j];
            c[i][j]=c[i][j-1]+b[i][j];
        }
    for(int i=k;i<=n;i++)
        for(int j=k;j<=n;j++)
        ans=max(c[i][j]-c[i][j-k]-c[i-k][j]+c[i-k][j-k],ans);

    cout<<ans;



}
