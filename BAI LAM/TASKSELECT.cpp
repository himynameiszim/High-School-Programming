#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const ll mod=1e9+7;

struct Tmatrix
{
    int sz;
    vector<vector<ll>>vt;

    Tmatrix(){}
    Tmatrix(int n):sz(n),vt(vector<vector<ll>>(n+1,vector<ll>(n+1))){}
    Tmatrix(int n,vector<vector<ll>> vt):sz(n),vt(vt){}
    Tmatrix operator*(Tmatrix a)
    {
        Tmatrix res(a.sz);
        for(int i=1;i<=sz;i++)
        {
            for(int j=1;j<=sz;j++)
            {
                for(int k=1;k<=sz;k++)
                {
                    res.vt[i][j]=(res.vt[i][j]+vt[i][k]*a.vt[k][j]%mod)%mod;
                }
            }
        }
        return res;
    }
};

Tmatrix power(Tmatrix a, ll b)
{
    Tmatrix res=a;
    b--;
    while(b)
    {
        if(b&1)res=res*a;
        a=a*a;
        b/=2;
    }
    return res;
}

int cnt;
vector<pii>edge;
void trans(int l,int r,int d)
{
    int pre=l;
    for(int i=1;i<d;i++)
    {
        edge.push_back({pre,cnt});
        pre=cnt;
        cnt++;
    }
    edge.push_back({pre,r});
}

void process()
{
    int n,k;
    cin>>k>>n;
    cnt=k+1;
    edge.clear();
    for(int i=1;i<=k;i++)
    {
        trans(i-1,i,i);
        trans(i,i,i);
    }
    Tmatrix a((k)*(k)+1);

    for(auto&c:edge)
    {
        a.vt[c.F+1][c.S+1]=1;
    }
    a=power(a,n);
    cout<<a.vt[1][k+1]<<"\n";
}

int main()
{
    freopen("TASKSELECT.inp","r",stdin);
    freopen("TASKSELECT.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    cin>>test;
    while(test--)
    process();
}
