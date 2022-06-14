#include<bits/stdc++.h>

using namespace std;

const int M=2e6+12;
const int N=3e5+15;

int a[N],n,k,b[M],p[M],ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("gcdarr.inp","r",stdin);
    freopen("gcdarr.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<M;i++)p[i]=p[i-1]+b[i];

    for(int g=1;g<M;g++)
    if(g<=k)ans=g;
    else
    {
        int d=0;
        for(int boig=g;boig<M;boig+=g)
            d+=p[boig]-p[max(boig-k-1,0)];
        if(d==n)
            ans=g;
    }
    cout<<ans;
}
