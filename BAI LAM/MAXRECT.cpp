#include<bits/stdc++.h>

using namespace std;


const int M=1e3+3;

int ans,n,m,l[M][M],r[M][M],b[M][M];
int a[M][M];
vector<int>vt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>a[i][j];

    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
            if(a[i][j]==1)
                b[i][j]=b[i-1][j]+1;
            else b[i][j]=0;

    for(int i=1;i<=n;i++)
    {
        vt.clear();
        for(int j=1;j<=m;j++)
        {
            while(!vt.empty()&&b[i][vt.back()]>=b[i][j])vt.pop_back();
            if(vt.empty())l[i][j]=0;
            else l[i][j]=vt.back();
            vt.push_back(j);
        }
    }

    for(int i=1;i<=n;i++)
    {
        vt.clear();
        for(int j=m;j>=1;j--)
        {
            while(!vt.empty()&&b[i][vt.back()]>=b[i][j])vt.pop_back();
            if(vt.empty())r[i][j]=m+1;
            else r[i][j]=vt.back();
            vt.push_back(j);
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        ans=max(ans,(r[i][j]-l[i][j]-1)*b[i][j]);

    cout<<ans;
}
