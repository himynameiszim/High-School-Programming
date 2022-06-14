#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf=1e9+1;

void process()
{
    ll n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    auto check=[&](int mid)->int
    {
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            res+=min(a[i],mid);
        }
        return res>=m;
    };

    int l=0,r=inf;
    while(r-l>1)
    {
        int m=(l+r)/2;
        if(check(m))r=m;
        else l=m;
    }
    if(r==inf)
    {
        cout<<-1;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=min(a[i],r);
        m-=a[i];
    }
//    cout<<m<<"\n";
    for(int i=1;i<=n&&m<0;i++)
    {
        if(a[i]==r)
        {
            a[i]--;
            m++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    freopen("SHARE.inp","r",stdin);
    freopen("SHARE.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
//    cin>>test;
    while(test--)
    {
        process();
    }

}

