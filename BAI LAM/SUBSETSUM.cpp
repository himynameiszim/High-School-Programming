//Thầy Hoàng
//AC
#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
using namespace std;

const int mx=1e6+1;

int f[mx],a[101],n,m;
queue<int>qu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("SUBSETSUM.inp","r",stdin);
    freopen("SUBSETSUM.out","w",stdout);

    cin>>n>>m;
    if(m>1e6){cout<<"NO";return 0;}
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=0;i<mx;i++)
        if(i==0||f[i]>0)
        for(int j=f[i]+1;j<=n;j++)
        if(i+a[j]<=mx)
        {
            if(f[i+a[j]]==0)f[i+a[j]]=j;
            else f[i+a[j]]=min(f[i+a[j]],j);
        }

    if(f[m]!=0)
    {
        cout<<"YES\n";
        vector<int>vt;
        while(m>0)
        {
            vt.push_back(f[m]);
            m-=a[f[m]];
        }
        for(int i=vt.size()-1;i>=0;i--)cout<<vt[i]<<" ";
    }
    else cout<<"NO\n";

}
