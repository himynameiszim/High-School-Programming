#include<bits/stdc++.h>

using namespace std;

const int M=1e5+5;

int n,k,a[M];

int check(int m)
{
    int temp=0;
    for(int i=0;i<n;i++)
        temp+=a[i]/m;
    if(temp>=k)return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("PART.inp","r",stdin);
    freopen("PART.out","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];

    int l=0,r=1e9+9;
    while(r-l>1)
    {
        int m=(l+r)/2;
        if(check(m))l=m;
        else r=m;
    }
    cout<<l;
}
