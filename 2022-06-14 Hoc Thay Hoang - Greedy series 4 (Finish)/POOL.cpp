#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int,int> pii;

void process()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    auto check=[&](int lane)->int
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<=lane;i++)pq.push(0);
        for(int i=1;i<=n;i++)
        {
            int u=pq.top();
            pq.pop();
            if(u+a[i]>m)return 0;
            pq.push(u+a[i]);
        }
        return 1;
    };
    int l=0,r=n+1;
    while(r-l>1)
    {
        int m=(l+r)/2;
        if(check(m))r=m;
        else l=m;
    }
    cout<<r;
}

int main()
{
    freopen("POOL.inp","r",stdin);
    freopen("POOL.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}

