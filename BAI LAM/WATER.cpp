#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int M=1e3+3;
const int x[]={0,0,-1,1};
const int y[]={-1,1,0,0};

ll ans;
int a[M][M],f[M][M],m,n;

struct cmp
{
    bool operator()(ii b,ii c)
    {
        return a[c.F][c.S]<a[b.F][b.S];
    }
};

priority_queue<ii,vector<ii>, cmp> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    freopen("WATER.inp","r",stdin);
    freopen("WATER.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>a[i][j];
    for(int i=1;i<=n;i++)pq.emplace(i,1),pq.emplace(i,m),f[i][m]=f[i][1]=1;
    for(int j=1;j<=m;j++)pq.emplace(1,j),pq.emplace(n,j),f[1][j]=f[n][j]=1;

    int curmx=0;

    while(pq.size())
    {
        int i,j;
        tie(i,j)=pq.top();
        curmx=max(curmx,a[i][j]);
        pq.pop();
        for(int k=0;k<4;k++)
        {
            int ii=i+x[k],jj=j+y[k];
            if(ii>0&&ii<=n&&jj>0&&jj<=m&&!f[ii][jj])
            {
                f[ii][jj]=1;
                pq.emplace(ii,jj);
                ans+=max(0,curmx-a[ii][jj]);
            }
        }
    }
    cout<<ans;
}

