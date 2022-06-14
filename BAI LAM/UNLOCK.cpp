#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=1e5+5;

ll a[M],pre[M],ans=1e18,cur,c;

int n;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("UNLOCK.inp","r",stdin);
    freopen("UNLOCK.out","w",stdout);

    cin>>n>>c;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];


    for(int i=1;i<=n;i++)
    {
        int op=lower_bound(a+1,a+1+n,a[i])-a;
        int ed=upper_bound(a+1,a+1+n,a[i])-a;
        ll moc=a[i];

        cur=0;
        ll d=lower_bound(a+1,a+op,moc-c/2.0)-a;
        d--;
        cur+=pre[d]+(c-moc)*(d);
        cur+=moc*(i-1-d)-(pre[i-1]-pre[d]);
        d=lower_bound(a+ed,a+n+1,moc+c/2.0)-a;
        d--;
        cur+=(pre[d]-pre[i])-moc*(d-i);
        cur+=c*(n-d)-(pre[n]-pre[d])+moc*(n-d);
        ans=min(ans,cur);
    }
    cout<<ans;
}

