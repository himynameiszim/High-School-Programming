#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

void process()
{
    int n;
    ll h,sum=0;
    cin>>n>>h;
    vector<pii> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].F;
        sum+=a[i].F;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].S;
    }
    sort(a.begin()+1,a.end(),[](pii a, pii b){return a.S<b.S;});
    priority_queue<int> pq;

    int cnt=0,mx=0;
    for(int i=1;i<=n;i++)
    {
        pq.push(a[i].F);
        if(sum-a[i].F+a[i].S>=h)
        {
            sum-=a[i].F;
            cnt++;
        }
        else
        {
            sum-=a[i].F;
            h-=pq.top();;
            pq.pop();
        }
    }
    cout<<cnt<<"\n";
}

int main()
{
    freopen("ESCAPE.inp","r",stdin);
    freopen("ESCAPE.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    cin>>test;
    while(test--)
    process();
}
