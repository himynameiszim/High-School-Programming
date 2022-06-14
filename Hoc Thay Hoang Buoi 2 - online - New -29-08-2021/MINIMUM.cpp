#include<bits/stdc++.h>

using namespace std;

const int M=5e5+5;

deque<int> dq;

int ans[M],a[M],n,k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("MINIMUM.inp","r",stdin);
    freopen("MINIMUM.out","w",stdout);

    cin>>n>>k;
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++)
    {
        while(dq.size()&&i-dq.front()+1>k)dq.pop_front();
        while(dq.size()&&a[dq.back()]>=a[i])dq.pop_back();
        if(dq.empty())ans[i]=a[i];
        else ans[i]=a[dq.front()];
        dq.push_back(i);
    }
    for(int i=k-1; i<n; i++)cout<<ans[i]<<"\n";
}
