#include<bits/stdc++.h>

using namespace std;

const int M=202;

vector<int>vt[M];
int n,m,u,v,mode,flag[M],from[M],d,maxd;
stack<int> stk,ans;

void dfs1(int u)
{
    if(u==1&&d>maxd)
    {
        maxd=d;
        ans=stk;
        if(d==n)exit(0);
        return ;
    }
    for(auto&c:vt[u])
        if(c<u&&!flag[c])
        {
            d++;
            flag[c]=1;
            from[c]=u;
            stk.push(c);
            dfs1(c);
            stk.pop();
            flag[c]=0;
            d--;
        }
}

void dfs(int u)
{
    if(u==n)
    {
        flag[1]=0;
        dfs1(n);
    }
    else
    for(auto&c:vt[u])
    {
        if(c>u&&!flag[c])
        {
            flag[c]=1;
            from[c]=u;
            d++;
            stk.push(c);
            dfs(c);
            stk.pop();
            flag[c]=0;
            d--;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("EWTOUR.inp","r",stdin);
    freopen("EWTOUR.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    flag[1]=1;
    dfs(1);
    cout<<maxd<<"\n";
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }cout<<1;
}
