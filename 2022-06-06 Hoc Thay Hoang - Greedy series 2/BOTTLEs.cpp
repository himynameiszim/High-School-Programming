#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int M=1e6+6;

int a[M];
ll s[M],dp[M],p[M],tr[M];

void process()
{
    int n,k;
    cin>>n>>k;
    k--;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    deque<int> dq;
    auto PUSH=[&](int i)->void
    {
        while(dq.size()&&-p[dq.back()]>=-p[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        while(dq.size()&&dq.front()+k<i)
        {
            dq.pop_front();
        }
    };
    p[0]=-a[1];
    PUSH(0);
    for(int i=1;i<=k;i++)
    {
        dp[i]=dp[i-1]+a[i];
        p[i]=-a[i+1];
        PUSH(i);
        tr[i]=-1;
    }
    for(int i=k+1;i<=n;i++)
    {
        dp[i]=p[dq.front()]+s[i];
        tr[i]=dq.front();
        p[i]=dp[i]-s[i+1];
        PUSH(i);
    }
    int t=n;
    vector<int> v;
    while(t>0)
    {
        for(int j=tr[t]+2;j<=t;j++)
        v.push_back(j);
        t=tr[t];
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<" "<<dp[n]<<"\n";
    for(auto&c:v)
    {
        cout<<c<<" ";
    }
}

int main()
{
    freopen("BOTTLEs.inp","r",stdin);
    freopen("BOTTLES.out","w",stdout);
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}

