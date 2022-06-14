#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,d;

int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin>>n;
    d=sqrt(n);
    if(d*d==n)
    {
        cout<<d<<" "<<d;
    }
    else if(d*(d+1)>=n)
    {
        cout<<d<<" "<<d+1;
    }
    else
    {
        cout<<d<<" "<<d+2;
    }
}
