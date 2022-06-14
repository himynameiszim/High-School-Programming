#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=4e5+20;

int a[M],l[M],r[M],n,g[M];
ll ans;
vector<int> vt;

void process()
{
    vt.clear();
    for(int i=0; i<n; i++)
    {
        while(vt.size()&&a[vt.back()]>a[i])vt.pop_back();
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

    for(ll i=0; i<n; i++)
    {
        ans+=(i-l[i])*(r[i]-i)*a[i];
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("WEIGHT.inp","r",stdin);
    freopen("WEIGHT.out","w",stdout);

    cin>>n;
    for(int i=0; i<n; i++)cin>>a[i];
    process();
    for(int i=0; i<n; i++)a[i]=-a[i];
    process();
    cout<<-ans;

}
