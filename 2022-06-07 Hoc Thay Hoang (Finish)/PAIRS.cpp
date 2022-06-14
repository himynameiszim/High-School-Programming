#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


const int D=10;
void process()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=D-a[i];
    }
    ll ans=0;
    vector<int> st;
    for(int i=1;i<=n;i++)
    {
        int tmp=0;
        while(st.size()&&a[st.back()]>=a[i])
        {
            ans++;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    reverse(a.begin()+1,a.end());
    for(int i=1;i<=n;i++)
    {
        while(st.size()&&a[st.back()]>=a[i])
        {
            if(a[i]!=a[st.back()])ans++;
            st.pop_back();
        }
        st.push_back(i);;
    }
    cout<<ans;
}

int main()
{
    freopen("PAIRS.inp","r",stdin);
    freopen("PAIRS.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cerr.tie(0);
    int test=1;
//    cin>>test;
    while(test--)
    {
        process();
    }

}

