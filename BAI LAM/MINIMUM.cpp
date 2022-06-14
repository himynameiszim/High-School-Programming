#include<bits/stdc++.h>

using namespace std;

const int M=5e5+5;

deque<int>dq;

int a[M],n,k,ans[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("MINIMUM.inp","r",stdin);
    freopen("MINIMUM.out","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        while(!dq.empty()&&a[i]<a[dq.back()])dq.pop_back();
        while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();
        dq.push_back(i);
        ans[i]=a[dq.front()];
    }
    for(int i=k-1;i<n;i++)cout<<ans[i]<<"\n";
}
