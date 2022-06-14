#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


const int M=(1<<16)+16;

map<int,int>mp;
vector<ii> vt;

int f[16][4][M];

int t;

int pos(int p,int t)
{

    int i=p/4,j=p%4;
    for(int k=1;k<=t;k++)
    {
        swap(i,j);
        j=3-j;
    }
    return i*4+j;
}

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("punch.inp","r",stdin);
    freopen("punch.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        mp[t]++;
    }
    for(auto &c:mp)
        vt.push_back(c);

    for(int i=0;i<vt.size();i++)
    {
        for(int j=0;j<16;j++)
            f[j][0][i]=1-((vt[i].F>>j)&1);

        for(int k=1;k<=3;k++)
            for(int j=0;j<16;j++)
                f[j][k][i]=f[pos(j,k)][0][i];
    }

    int ans=1e9+7;
    for(int j=0;j<16;j++)
        for(int jj=j+1;jj<16;jj++)
        {
            int cur=0;
            for(int i=0;i<vt.size();i++)
            {
                int goc=1e9+7;
                for(int k=0;k<4;k++)
                goc=min((f[j][k][i]+f[jj][k][i])*vt[i].S,goc);
                cur+=goc;
            }
            ans=min(ans,cur);
        }
    cout<<ans;
}
