#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef long long ll;

const int M=1e6+6;

ll a[M],L[M],R[M],n,test;
// chặt nhị phân
// chặt nhị phân độ dài dãy

ll gcd(ll a,ll b)
{
    while(a*b>0)
    {
        if(a>b)a%=b;
        else b%=a;
    }
    return a+b;
}

int check(int m)
{
    for(int i=0;i<n;i++)
        if(i%m==0)L[i]=a[i];
        else L[i]=gcd(L[i-1],a[i]);

    for(int i=n-1;i>=0;i--)
        if(i%m==0)R[i]=a[i];
        else R[i]=gcd(R[i+1],a[i]);
    for(int i=0;i<n;i++)
    {
        int j=i+m-1;
        if(j>=n)break;
        if(gcd(L[j],R[i])!=1)
            return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("cdsubseg.inp","r",stdin);
    freopen("cdsubseg.out","w",stdout);

    cin>>test;
    while(test--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            a[i]=abs(a[i]);
        }

        int l=0,r=n+1;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(check(m))l=m;
            else r=m;
        }
        cout<<l<<"\n";
    }



}

