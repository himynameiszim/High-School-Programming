#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void process()
{
    ll n,m,k,a,b;
    cin>>n>>m>>k>>a>>b;
    ll x=min(n/a,m/b);
    ll left=n+m-x*(a+b);
    if(left>=k)cout<<x<<"\n";
    else
    {
        k-=left;
        k=(k-1+(a+b))/(a+b);
        cout<<max(0ll,x-k)<<"\n";
    }
}

int main()
{
    freopen("ACTIVITY.inp","r",stdin);
    freopen("ACTIVITY.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    cin>>test;
    while(test--)
    {
        process();
    }

}
