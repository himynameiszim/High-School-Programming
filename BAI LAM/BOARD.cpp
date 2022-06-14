
//Thầy Hoàng
#include<bits/stdc++.h>

using namespace std;

const int M=1e3+3;

int a[M][M],f[M][M],n,m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("board.inp","r",stdin);
    freopen("board.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>a[i][j];

    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
            f[i][j]=max(f[i][j-1],max(f[i-1][j-1],f[i+1][j-1]))+a[i][j];


    int k=1;

    for(int i=1;i<=n;i++)
        if(f[i][m]>f[k][m])k=i;

    vector<int> vt;
    vt.push_back(k);

    cout<<f[k][m]<<"\n";

    for(int j=m;j>1;j--)
    if(f[k][j]==f[k][j-1]+a[k][j])vt.push_back(k);
    else if(f[k][j]==f[k-1][j-1]+a[k][j])
    {
        vt.push_back(k-1);
        k--;
    }
    else
    {
        vt.push_back(k+1);
        k++;
    }
    reverse(vt.begin(),vt.end());
    for(int i=0;i<vt.size();i++)
        cout<<vt[i]<<" "<<i+1<<"\n";
}
