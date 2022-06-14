#include<bits/stdc++.h>

using namespace std;

const int M=1e6+6;
const int N=1e5+5;

int n,a[N],b[M],p[N],e[N],f[N],d[N],t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("lines.inp","r",stdin);
    freopen("lines.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        b[t]=i;
    }

    for(int i=1;i<=n;i++)
        p[i]=b[a[i]];

        int l=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=lower_bound(e+1,e+1+l,p[i])-e;
        if(f[i]>l)l++;
        e[f[i]]=p[i];
        d[f[i]]=i;
    }

    cout<<l<<"\n";

    vector<int> vt;
    vt.push_back(d[l]);


    for(int i=n;i>0;i--)
    {
        if(f[i]<l&&p[i]<p[vt.back()])
        {
            l=f[i];
            vt.push_back(i);
        }
    }

    for(int i=vt.size()-1;i>=0;i--)cout<<a[vt[i]]<<" ";
}
