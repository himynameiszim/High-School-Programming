#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
vector<ll>ngc,xuoi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for(ll i=1;i*i<=n;i++)
    if(n%i==0)
    {
        xuoi.push_back(i);
        ngc.push_back(n/i);
    }
    if(xuoi.size()&&ngc.size()&&xuoi.back()==ngc.back())xuoi.pop_back();
    for(int i=0;i<xuoi.size();i++)
        cout<<xuoi[i]<<"\n";
    for(int i=int(ngc.size())-1;i>=0;i--)
        cout<<ngc[i]<<"\n";
}
