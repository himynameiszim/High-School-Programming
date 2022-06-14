#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,ans,k;
int a[22];
vector<int> vt;

int locate(int i)
{
    int ans=0;
    while(i>vt[ans])ans++;
    vt.erase(vt.begin()+ans);
    return ans;
}

ll gt(int b)
{
    if(b<2)return 1;
    ll ans=1;
    for(int i=2;i<=b;i++)ans*=i;
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("permutation.inp","r",stdin);
    freopen("permutation.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        vt.push_back(a[i]);
    }
    sort(vt.begin(),vt.end());
    ans=0;
    for(int i=0;i<n;i++)
        ans+=locate(a[i])*gt(n-i-1);
    cout<<ans+1<<"\n";


    cin>>k;k--;
    vt.clear();
    for(int i=1;i<=n;i++)vt.push_back(i);
    for(int i=1;i<=n;i++)
    {
        ll t=gt(n-i);
        int j=0;
        while(k>=t)
        {
            k-=t;
            j++;
        }
        cout<<vt[j]<<" ";
        vt.erase(vt.begin()+j);
    }

}
