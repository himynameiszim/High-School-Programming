#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int,int> pii;

const int M=1e5+5;

vector<vector<pii>> port(M,{{0,0}});
vector<pii>ray[M];
vector<int> out(M,0);
void process()
{
    int n,m;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        ray[l].push_back({r,i});
    }
    priority_queue<pii> pqmx;///{time,id}
    priority_queue<pii,vector<pii>,greater<pii> > pqmn;
    for(int i=1;i<=m;i++)
    {
        pqmn.push({0,i});
    }
    for(int i=0;i<M;i++)
    {
        for(auto&c:ray[i])
        {
            if(pqmn.top()<=)
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}
