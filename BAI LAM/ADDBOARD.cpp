//Thầy Hoàng
//Difference Array
//
#include<bits/stdc++.h>

using namespace std;

const int N=1e3+3;

int a[N][N],d[N][N],n,q,lx,ly,rx,ry,m,M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("addboard.inp","r",stdin);
    freopen("addboard.out","w",stdout);

    cin>>n>>m>>q;
    for(int j=0;j<q;j++)
    {
        cin>>lx>>ly>>rx>>ry>>M;
        for(int i=lx;i<=rx;i++)
        {
            d[i][ly]+=M;
            d[i][ry+1]-=M;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=a[i][j-1]+d[i][j];
            cout<<a[i][j]<< " ";
        }
        cout<<"\n";
    }

}
