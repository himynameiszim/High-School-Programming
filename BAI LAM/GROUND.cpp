#include<bits/stdc++.h>

using namespace std;

const int M=1e3+3;

int n,m,k,h[M][M],a[M][M],b[M][M],c[M][M],d[M][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>h[i][j];

    for(int i=1;i<=n;i++)
    {
        deque<int>q;
        for(int j=1;j<=m;j++)
        {
            while(!q.empty()&&q.front()<=j-k)q.pop_front();
            while(!q.empty()&&h[i][q.back()]<=h[i][j])q.pop_back();
            q.push_back(j);
            a[i][j]=h[i][q.front()];
        }
    }

    for(int j=1;j<=m;j++)
    {
        deque<int>q;
        for(int i=1;i<=n;i++)
        {
            while(!q.empty()&&q.front()<=i-k)q.pop_front();
            while(!q.empty()&&a[q.back()][j]<=a[i][j])q.pop_back();
            q.push_back(i);
            b[i][j]=a[q.front()][j];
        }
    }

    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)h[i][j]=-h[i][j];

    for(int i=1;i<=n;i++)
    {
        deque<int>q;
        for(int j=1;j<=m;j++)
        {
            while(!q.empty()&&q.front()<=j-k)q.pop_front();
            while(!q.empty()&&h[i][q.back()]<=h[i][j])q.pop_back();
            q.push_back(j);
            c[i][j]=h[i][q.front()];
        }
    }


    for(int j=1;j<=m;j++)
    {
        deque<int>q;
        for(int i=1;i<=n;i++)
        {
            while(!q.empty()&&q.front()<=i-k)q.pop_front();
            while(!q.empty()&&c[q.back()][j]<=c[i][j])q.pop_back();
            q.push_back(i);
            d[i][j]=c[q.front()][j];
        }
    }



    int ans=1e9;
    for(int i=k;i<=n;i++)
        for(int j=k;j<=m;j++)ans=min(ans,b[i][j]+d[i][j]);

    cout<<ans;

}
