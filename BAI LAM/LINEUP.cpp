#include<bits/stdc++.h>

using namespace std;

stack<int> st;

int a[100009],n,ans[100009];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("LINEUP.inp","r",stdin);
    freopen("LINEUP.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];

    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&a[st.top()]<=a[i])st.pop();
        if(st.empty())ans[i]=-1;
        else ans[i]=st.top();
        st.push(i);
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";

}
