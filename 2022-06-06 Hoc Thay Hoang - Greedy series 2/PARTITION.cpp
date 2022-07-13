#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

void process()
{
    priority_queue<int,vector<int>,greater<int>> pq;
    int L,n,sum=0;
    cin>>L>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        pq.push(t);sum+=t;
    }
    if(sum!=L)
    {
        pq.push(L-sum);
    }
    while(pq.size()>1)
    {
        int d=pq.top();
        pq.pop();
        d+=pq.top();
        pq.pop();
        ans+=d;
        pq.push(d);
    }
    cout<<ans;
}

int main()
{
    freopen("PARTITION.inp","r",stdin);
    freopen("PARTITION.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}
