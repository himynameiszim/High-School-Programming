#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int,int> pii;

void process()
{
    int n;
    cin>>n;
    priority_queue<pii> pq;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        pq.push({t,i});
    }
    while(pq.size())
    {
        vector<pii> tmp;
        int u,id;
        tie(u,id)=pq.top();
        pq.pop();
        for(int i=1;i<=u;i++)
        {
            pii t=pq.top();
            pq.pop();
            t.F--;
            if(t.F)tmp.push_back(t);
            cout<<id<<" "<<t.S<<"\n";
        }
        for(auto&c:tmp)pq.push(c);
    }
}

int main()
{
    freopen("TENNIS.inp","r",stdin);
    freopen("TENNIS.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}
