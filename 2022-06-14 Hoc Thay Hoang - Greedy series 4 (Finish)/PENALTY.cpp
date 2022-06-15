#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

void process()
{
    int n,a,b;
    cin>>n>>a>>b;
    vector<pii> vt;
    priority_queue<int,vector<int>,greater<int>> pq;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        int t,p;
        cin>>t>>p;
        vt.push_back({t,p});
        sum+=p;
    }
    sort(vt.begin(),vt.end());
    ll ans=0;
    for(auto&c:vt)
    {
        ans+=c.S;
        pq.push(c.S);
        while((int)pq.size()>min(b-a,max(c.F-a,0)))
        {
            ans-=pq.top();
            pq.pop();
        }
    }
    cout<<sum-ans;

}

int main()
{
    freopen("PENALTY.inp","r",stdin);
    freopen("PENALTY.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}

