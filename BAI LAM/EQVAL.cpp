#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int M=2e5+10;

int a[M],q,n,m,k;
ll ans[M];
map<int,ll> fina,cur;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("EQVAL.inp","r",stdin);
    freopen("EQVal.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        fina[a[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        ans[i]=ans[i-1]-fina[a[i]]*cur[a[i]]+(cur[a[i]]+1)*(fina[a[i]]-1);
        cur[a[i]]++;
        fina[a[i]]--;
    }

    for(int i=0;i<m;i++)
    {
        cin>>q;
        cout<<ans[q]<<"\n";
    }





}
