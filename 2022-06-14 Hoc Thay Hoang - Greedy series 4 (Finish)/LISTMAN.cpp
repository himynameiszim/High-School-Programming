#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int,int> pii;

void process()
{
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>0)
        pq.push({a[i],i});
    }
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='S')
        {
            int p,v;
            cin>>p>>v;
            a[p]=v;
            if(v>0)
            {
                pq.push({a[p],p});
            }
        }
        else
        {
            while(pq.size())
            {
                int v,p;
                tie(v,p)=pq.top();
                if(v==a[p])break;
                pq.pop();
            }
            if(pq.size())cout<<pq.top().F<<"\n";
            else cout<<0<<"\n";
        }
    }
}

int main()
{
    freopen("LISTMAN.inp","r",stdin);
    freopen("LISTMAN.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}
