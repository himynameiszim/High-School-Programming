#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

const int M=1e6+6;

vector<ii> vt;
int a[M],n,k;
ll ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("GAS.inp","r",stdin);
    freopen("GAS.out","w",stdout);

    cin>>n>>k;
    for(int i=0; i<n; i++)cin>>a[i];
    int frontid=0,siz=0;
    for(int i=0; i<n; i++)
    {
        while(int(vt.size())>frontid&&vt.back().F>a[i])
        {
            siz-=vt.back().S;
            vt.pop_back();
        }
        if(siz<k)
        {
            vt.emplace_back(a[i],k-siz);
        }
        siz=k;
        ans+=vt[frontid].F;
        siz--;
        vt[frontid].S--;
        if(vt[frontid].S==0)frontid++;
    }
    cout<<ans;
}
