#include <bits/stdc++.h>

using namespace std;

const int mxn=5e5+5;
const int inf=1e9+7;

int m,n,a[mxn],aR[mxn],l[mxn],r[mxn];
long long mx;

stack<int>st,stR;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("RECT.inp","r",stdin);
    freopen("RECT.out","w",stdout);

    cin>>m>>n;
    for(int i=1;i<=n;i++){cin>>a[i];aR[i]=m-a[i];}

    a[0]=aR[0]=a[n+1]=aR[n+1]=-inf;
    //xét a[]
    st.push(0);stR.push(n+1);

    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&a[st.top()]>=a[i])
            st.pop();
        l[i]=st.top();
        st.push(i);
    }

    for(int i=n;i>0;i--)
    {
        while(!stR.empty()&&a[stR.top()]>=a[i])
            stR.pop();
        r[i]=stR.top();
        stR.push(i);
        mx=max(mx,(r[i]-l[i]-1ll)*a[i]);
    }

    //xét aR[]
    while(!st.empty())st.pop();
    while(!stR.empty())stR.pop();
    st.push(0);stR.push(n+1);
    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&aR[st.top()]>=aR[i])
            st.pop();
        l[i]=st.top();
        st.push(i);
    }

    for(int i=n;i>0;i--)
    {
        while(!stR.empty()&&aR[stR.top()]>=aR[i])
            stR.pop();
        r[i]=stR.top();
        stR.push(i);
        mx=max(mx,(r[i]-l[i]-1ll)*aR[i]);
    }

    cout<<mx;

}
