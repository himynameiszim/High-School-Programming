#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod=123456789;
const int M=1e5+5;

vector<int> vt;

ll g[10][M],s[10][M],ans,k;
int n;

void khoi_tao()
{
    for(int i=0;i<10;i++)
    {
        s[i][0]=10;
        g[i][0]=i;
    }

    for(int j=1;j<M;j++)
        for(int i=0;i<10;i++)
        {
            if(i*3<10)
                s[i][j]=s[i*3][j-1];
            else
                s[i][j]=s[(i*3)%10][j-1]*s[i*3/10][j-1]%mod;
        }

    for(int j=1;j<M;j++)
        for(int i=0;i<10;i++)
        {
            if(i*3<10)
                g[i][j]=g[i*3][j-1];
            else
                g[i][j]=((g[(i*3)/10][j-1]*s[(i*3)%10][j-1])%mod+g[(i*3)%10][j-1]%mod)%mod;
        }
}

void xuly()
{
    ans=0;
    vt.clear();
    cin>>k>>n;
    while(k>0)
    {
        vt.push_back(k%10);
        k/=10;
    }
    reverse(vt.begin(),vt.end());
    for(auto&c:vt)
        ans=(ans*s[c][n]+g[c][n])%mod;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("triple.inp","r",stdin);
    freopen("triple.out","w",stdout);

    khoi_tao();

    int t=1;
    cin>>t;
    while(t--)
    {
        xuly();
    }
}
