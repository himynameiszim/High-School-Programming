#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=5e5+5;

ll ans;
int a[M],l[M],r[M],m,n;
vector<int> vt;

void nani()
{
    vt.clear();
    for(int i=0; i<n; i++)
    {
        while(vt.size()&&a[vt.back()]>=a[i])vt.pop_back();
        if(vt.empty())l[i]=-1;
        else l[i]=vt.back();
        vt.push_back(i);
    }
    vt.clear();
    for(int i=n-1; i>=0; i--)
    {
        while(vt.size()&&a[vt.back()]>=a[i])vt.pop_back();
        if(vt.empty())r[i]=n;
        else r[i]=vt.back();
        vt.push_back(i);
    }
    for(int i=0; i<n; i++)
        ans=max(ans,(r[i]-l[i]-1ll)*a[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("RECT.inp","r",stdin);
    freopen("RECT.out","w",stdout);

    cin>>m>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    nani();
    for(int i=0; i<n; i++)
        a[i]=m-a[i];
    nani();

    cout<<ans;


}
