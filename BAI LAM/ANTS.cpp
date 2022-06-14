#include<bits/stdc++.h>

using namespace std;


typedef long long ll;

const int M=1e5+5;

ll a[M],k,n,ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("ants.inp","r",stdin);
    freopen("ants.out","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //sort(a,a+n,[](int a,int b){return abs(a)<abs(b);});
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)ans=max(ans,-a[i]);
        else ans=max(ans,k-a[i]);
    }
    cout<<ans;
}
