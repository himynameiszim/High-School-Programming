#include<bits/stdc++.h>

using namespace std;

const int M=5e2+10;

int n,m,au[M][M],ag[M][M],f[M][M];

int dp(int x,int y)
{
    if(x<=0||y<=0)return 0;
    else
    return f[x][y]=max(ag[x][y]+dp(x,y-1),au[x][y]+dp(x-1,y));
}

void khudequy()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            ag[i][j]+=ag[i-1][j];
            au[i][j]+=au[i][j-1];
            f[i][j]=max(au[i][j]+f[i-1][j],ag[i][j]+f[i][j-1]);
        }
    cout<<f[n][m]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)f[i][j]=-1;


    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>au[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>ag[i][j];

    /*for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)au[i][j]+=au[i][j-1];

    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)ag[i][j]+=ag[i-1][j];

    cout<<dp(n,m)<<"\n";*/
    khudequy();
}
