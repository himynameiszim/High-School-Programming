#include<bits/stdc++.h>

using namespace std;

const int Mx=1e5+1;

int n,k,x,c[Mx],l[Mx],p[Mx], vt[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SHUFFLE.inp","r",stdin);
    freopen("SHUFFLE.out","w",stdout);

    cin>>n>>k>>x;

    iota(vt+1,vt+1+k,1);

    for(int i=0;i<x;i++)
        cin>>c[i]>>l[i]>>p[i];

    for(int i=x-1;i>=0;i--)
    {
        if(c[i]>p[i])
        for(int j=1;j<=k;j++)
        {
            if(vt[j]>=p[i]&&vt[j]<p[i]+l[i])vt[j]+=c[i]-p[i];
            else if(vt[j]>=p[i]+l[i]&&vt[j]<c[i]+l[i])vt[j]-=l[i];
        }
        else if(c[i]+l[i]<=p[i])
        for(int j=1;j<=k;j++)
        {
            if(vt[j]>=p[i]-l[i]&&vt[j]<p[i])vt[j]+=c[i]+l[i]-p[i];
            else if(vt[j]>=c[i]&&vt[j]<p[i]-l[i])vt[j]+=l[i];
        }
        else if(c[i]<p[i]&&c[i]+l[i]>p[i])
        for(int j=1;j<=k;j++)
        {
            if(vt[j]>=c[i]&&vt[j]<p[i])vt[j]+=l[i];
            else if(vt[j]>=p[i]&&vt[j]<p[i]+l[i])vt[j]+=-p[i]+c[i];
        }
    }
    for(int i=1;i<=k;i++)cout<<vt[i]<<" ";
}
