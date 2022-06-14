//Thầy Hoàng
//AC
#include<bits/stdc++.h>

using namespace std;

const int M=1e6+6;

int f[M],a[101],n,m,b[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("tugofwar.inp","r",stdin);
    freopen("tugofwar.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m+=a[i];
    }
    int bm=m;
    m/=2;

    for(int i=0;i<m;i++)
        if(i==0||f[i]>0)
        for(int j=f[i]+1;j<=n;j++)
        if(i+a[j]<=m)
        {
            if(f[i+a[j]]==0)f[i+a[j]]=j;
            else f[i+a[j]]=min(j,f[i+a[j]]);
        }
    while(f[m]==0)m--;
    int d=0;
    while(m>0)
    {
        b[f[m]]=1;
        d++;
        m-=a[f[m]];
    }
    cout<<d<<" "<<n-d<<"\n";;
    for(int i=1;i<=n;i++)if(b[i]==1)cout<<i<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++)if(b[i]==0)cout<<i<<" ";

}
