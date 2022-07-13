#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int M=2e3+3;
const int inf=1e9+9;

const int dx[]={-1,1,2,2,1,-1,-2,-2};
const int dy[]={-2,-2,-1,1,2,2,1,-1};

string s[M];
vector<int> adj[M*M];
int ans,num[M*M],low[M*M],f[M*M];


vector<int> st;
void dfs(int u)
{
//    cout<<"dfs: "<<u<<"\n";
    num[u]=low[u]=++num[0];
    st.push_back(u);
    for(auto&c:adj[u])
    {
        if(!num[c])
        {
            dfs(c);
            low[u]=min(low[u],low[c]);
        }
        else low[u]=min(low[u],num[c]);
    }
    if(num[u]==low[u])
    {
        int cnt=0;
        int v;
        do
        {
            cnt++;
            v=st.back();
            st.pop_back();
            low[v]=num[v]=inf;
        }while(v!=u);
        ans=max(ans,cnt);
    }
}

void process()
{
    int n,m;
    cin>>n>>m;
    int b=m;
    auto to1=[&](pii a)->int
    {
        return (a.F-1)*b+a.S;
    };
    auto to2=[&](int a)->pii
    {
        return {a/b+1,(a-1)%b+1};
    };
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]='@'+s[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='.')
            {
                for(int k=0;k<8;k++)
                {
                    if(i+dx[k]>=1&&i+dx[k]<=n&&j+dy[k]>=1&&j+dy[k]<=m&&s[i+dx[k]][j+dy[k]]=='.')
                    {
                        int u=to1({i,j});
                        int v=to1({i+dx[k],j+dy[k]});
                        f[u]=f[v]=1;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                    }
                }
            }
        }
    }
    for(int i=1;i<=b*b;i++)
    {
        if(!num[i]&&f[i])dfs(i);
    }
    cout<<ans;
}

int main()
{
    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    freopen("KNIGHT.inp","r",stdin);
//    freopen("KNIGHT.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}
