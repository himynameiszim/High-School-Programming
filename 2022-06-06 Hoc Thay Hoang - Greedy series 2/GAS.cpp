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
    for(int i=0;i<n;i++)cin>>a[i];
    deque<pii> st;
    int rmn=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        while(st.size()&&st.back().S>a[i])
        {
            rmn-=st.back().F;
            st.pop_back();
        }
        if(rmn!=k)
        {
            st.push_back({k-rmn,a[i]});
            rmn=k;
        }
        rmn--;
        pii tmp=st.front();
        st.pop_front();
        ans+=tmp.S;
        tmp.F--;
        if(tmp.F)st.push_front(tmp);
    }
    cout<<ans;
}

int main()
{
    freopen("GAS.inp","r",stdin);
    freopen("GAS.out","w",stdout);
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}


