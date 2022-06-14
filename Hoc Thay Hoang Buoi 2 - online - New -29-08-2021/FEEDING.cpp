#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=5e5+5;

int a[M],p[M],n;
ll ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("FEEDING.inp","r",stdin);
    freopen("FEEDING.out","w",stdout);

    cin>>n;
    for(int i=0; i<n; i++)cin>>p[i];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(i)a[i]=min(a[i-1],a[i]);
    }


    for(int i=0; i<n; i++)ans=ans+(ll)a[i]*p[i];
    cout<<ans;

}
