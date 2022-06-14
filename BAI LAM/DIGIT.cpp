//Thầy Hoàng
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
const int M=2e7;

ll indianmultiply(ll a,ll b,ll mod)
{
    ll ans=0;
    while(b)
    {
        if(b&1)ans=(ans+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}

ll power( ll k, ll b)
{
    ll ans=1,a=10;

    while(k)
    {
        if(k&1)
            ans=indianmultiply(ans,a,b);
        a=indianmultiply(a,a,b);
        k>>=1;
    }
    return ans;
}

ll a,b,k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("digit.inp","r",stdin);
    freopen("digit.out","w",stdout);

    cin>>a>>b>>k;
    /*
    tìm số thứ k của a/b tương đương với cần dưới của a*10^k/b%10
    nhưng không tính được phép 10^k*a/b
    ==> tính 10^(k-1)*a/b *10
    số cần tìm sẽ là số đầu tiên sau dấu phẩy của 10^(k-1)*a/b
    10^(k-1)*a/b để lấy phần thập phân thì cần lấy 10^(k-1)%b /b
    10^(k-1)%b  *10 /b sẽ lấy được số cần tìm
    */
    cout<<indianmultiply(a,power(k-1,b),b)*10/b;



}
