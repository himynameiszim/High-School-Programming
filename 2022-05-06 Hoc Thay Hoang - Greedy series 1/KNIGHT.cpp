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
int flag[M][M],cnt,ans,n,m;

void dfs(int x,int y)
{
    cnt++;
    flag[x][y]=1;
    for(int k=0;k<8;k++)
    {
        if(x+dx[k]>=1&&x+dx[k]<=n&&y+dy[k]>=1&&y+dy[k]<=m)
        {
            if(s[x+dx[k]][y+dy[k]]=='.'&&!flag[x+dx[k]][y+dy[k]])
            {
                dfs(x+dx[k],y+dy[k]);
            }
        }
    }
}

void process()
{
//    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]='@'+s[i];
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
//            cout<<s[i][j]*(1-flag[i][j])<<"\n";
            if(s[i][j]=='.'&&!flag[i][j])
            {
                dfs(i,j);
                ans=max(ans,cnt);
                cnt=0;
            }
        }
    }
    cout<<ans;
}

int main()
{
    freopen("KNIGHT.inp","r",stdin);
    freopen("KNIGHT.out","w",stdout);
//    freopen("inp.txt","r",stdin);
//    freopen("ans.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}
