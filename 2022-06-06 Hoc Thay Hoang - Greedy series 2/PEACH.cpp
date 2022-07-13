#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
//
//void process()
//{
//    int n,a,b;
//    cin>>n>>a>>b;
//    priority_queue<int> pq;
//    ll ans=0;
//    map<int,vector<int> > mp;
//    for(int i=1;i<=n;i++)
//    {
//        int t,y;
//        cin>>t>>y;
//        if(t<=a)pq.push(y);
//        else if(t<b)
//        mp[t].push_back(y);
//    }
//    int cur=a;
//
//    auto clct=[&](int t)-> void
//    {
//        while(cur<t&&pq.size())
//        {
//            ans+=pq.top();
//            pq.pop();
//            cur++;
//        }
//    };
//
//    for(auto&c:mp)
//    {
//        clct(c.F);
//        cur=c.F;
//        for(auto&d:c.S)
//        {
//            pq.push(d);
//        }
//        if(cur==b)continue;
//
//        ans+=pq.top();
//        pq.pop();
//        cur++;
//    }
//    clct(b);
//    cout<<ans;
//}

void process()
{
    int n,a,b;
    cin>>n>>a>>b;
    deque<pii> dq(n);
    priority_queue<int> pq;
    ll ans=0;
    map<int,vector<int> > mp;
    for(auto&c:dq)
    {
        cin>>c.F>>c.S;
    }
    sort(dq.begin(),dq.end());
    if(b-a>n)a=b-n;
    for(int i=a;i<b;i++)
    {
        while(dq.size()&&dq.front().F<=i)
        {
            pq.push(dq.front().S);
            dq.pop_front();
        }
        if(pq.size())
        {
            ans+=pq.top();
            pq.pop();
        }
    }
    cout<<ans;
}

int main()
{
    freopen("PEACH.inp","r",stdin);
    freopen("PEACH.out","w",stdout);
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}
