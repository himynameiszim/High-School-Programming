#include<bits/stdc++.h>

using namespace std;

const int M=333;

int b[M][M],ok[M];
vector<int> adj[M];

void dfs(int i,int b[])
{
    if(!ok[i])return;
    b[i]=1;
    for(auto&c:adj[i])if(!b[c])dfs(c,b);
}

void process()
{
    int n,m,k;
    cin>>n>>m>>k;;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int x=1;x<=n;x++)
    {
        sort(adj[x].begin(),adj[x].end());
        adj[x].resize(unique(adj[x].begin(),adj[x].end())-adj[x].begin());
    }
    int cnt=0;
    auto DFS=[&]()-> void
    {
        cnt++;
        for(int i=1;i<=n;i++)
        {
            fill(b[i],b[i]+n+1,0);
            dfs(i,b[i]);
        }
    };

    int re=0;
    while(k--)
    {
        char from;
        cin>>from;
        if(from == 'X')
        {
            int p;
            cin>>p;
            if(!ok[p])
            {
                ok[p]=1;
                re=1;
            }
        }
        else
        {
            int s,e;
            cin>>s>>e;
            if(re)
            {
                re=0;
                DFS();
            }
            if(s==e)cout<<"Y";
            else
            cout<<(b[s][e]?"Y":"N");
        }
    }
    cerr<<cnt;
}

int main()
{
    freopen("DLABYR.inp","r",stdin);
    freopen("DLABYR.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}
