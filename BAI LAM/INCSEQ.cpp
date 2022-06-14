//Thầy Hoàng
//21/06/2021
//AC
#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

const int M=1e5+5;

multiset<ii> st;
vector<int>vt[M];
int n,a[M],sd=1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("INCSEQ.inp","r",stdin);
    freopen("INCSEQ.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    vt[1].push_back(1);
    st.emplace(a[1],1);
    for(int i=2;i<=n;i++)
    {
        auto id=st.lower_bound(ii(a[i],0));
        if(id==st.begin())
        {
            sd++;
            st.emplace(a[i],sd);
            vt[sd].push_back(i);
        }
        else
        {
            id--;
            ii d=*id;
            st.erase(id);
            vt[d.S].push_back(i);
            d.F=a[i];
            st.insert(d);
        }
    }
    cout<<sd<<"\n";
    for(int i=1;i<=sd;i++)
    {
        for(auto&c:vt[i])cout<<c<<" ";
        cout<<"\n";
    }

}
