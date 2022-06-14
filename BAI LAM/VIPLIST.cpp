#include<bits/stdc++.h>

using namespace std;

const int M=1e5+5;

int ers[M],cur_deg[M];
vector<int> adj[M];

///chú í đa đồ thị

void process()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        sort(adj[i].begin(),adj[i].end());
        adj[i].resize(unique(adj[i].begin(),adj[i].end())-adj[i].begin());
        cur_deg[i]=adj[i].size();
    }

    auto Erase=[&](int u)-> void
    {
        queue<int> ers_que;
        ers_que.push(u);
        while(ers_que.size())
        {
            u=ers_que.front();
            ers_que.pop();
            if(ers[u])continue;
            ers[u]=1;
            for(auto&c:adj[u])
            {
                cur_deg[c]--;
                if(!ers[c]&&cur_deg[c]<k)ers_que.push(c);
            }
        }
    };

    for(int i=1;i<=n;i++)
    {
        if(cur_deg[i]<k&&!ers[i])
        {
            Erase(i);
        }
    }
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(!ers[i])ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(auto&c:ans)cout<<c<<" ";
}
int main()
{
    freopen("VIPLIST.inp","r",stdin);
    freopen("VIPLIST.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}
