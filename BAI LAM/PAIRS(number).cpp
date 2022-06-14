//AC
//Thầy Hoàng
//Số

#include<bits/stdc++.h>

using namespace std;

const int M=5e5+5;

int a[M],n,cnt;

stack<int>st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("pairs.inp","r",stdin);
    freopen("pairs.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        while(!st.empty()&&a[st.top()]<a[i]){st.pop();cnt++;}
        if(!st.empty())cnt++;
        st.push(i);
    }
    cout<<cnt;

}
