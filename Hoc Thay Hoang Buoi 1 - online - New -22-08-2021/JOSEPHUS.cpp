#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=1e7+7;

int f[M];
ll n,m,st,ed;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("JOSEPHUS.inp","r",stdin);
    freopen("JOSEPHUS.out","w",stdout);

    cin>>n>>m;
    cin>>st>>ed;
    f[1]=0;
    for(int i=2;i<=n;i++)
    {
        //ll p=f[i-1]-m;
        //f[i]=f[i-1]+p;
        ///==>
        ll p=(i-m);
        f[i]=(f[i-1]-p+i)%i;
    }
    cout<<(f[n]+st)%n<<" ";
    cout<<(0ll-(f[n]-ed)+n*n)%n;
}
