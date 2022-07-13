#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int M=5e5+25;
const int inf=1e9+9;

const int dx[]={-1,1,2,2,1,-1,-2,-2};
const int dy[]={-2,-2,-1,1,2,2,1,-1};

vector<pii> adj[M];
int flag[M];

void dfs(int u,int m)
{
    flag[u]=1;
    for(auto&c:adj[u])
    {
        if(c.S<=m&&!flag[c.F])
        {
            dfs(c.F,m);
        }
    }
}

void process()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
//        cout<<x<<" " <<y<<" "<<i<<"\n";
        adj[x].push_back({y,i});
    }
    int l=0,r=m+1;
    while(r-l>1)
    {
        for(int i=1;i<=n;i++)flag[i]=0;
        int m=(l+r)/2;
        dfs(1,m);
        if(flag[n])r=m;
        else l=m;
    }
    cout<<(r==m+1?-1:r);
}

int main()
{
    freopen("COMNET.inp","r",stdin);
    freopen("COMNET.out","w",stdout);
//    freopen("inp.txt","r",stdin);
//    freopen("ans.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}

