#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

const int Mx=1e5+1;

ii a[Mx];

int d, ans[Mx],n,m,cs[Mx];

set<ii>st;//lưu thời gian cho đến khi bến rảnh và stt bến

int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("SEAPORTs.inp","r",stdin);
//    freopen("seaports.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    iota(cs+1,cs+n+1,1);

    sort(cs+1,cs+n+1,[](int i,int j){return a[i].second<a[j].second;});

    for(int i=1;i<=m;i++)
        st.emplace(0,i);
    for(int i=1;i<=n;i++)
    {
        auto it=st.upper_bound(ii(a[cs[i]].first,m+1));
        if(it==st.begin())ans[cs[i]]=0;
        else
        {
            it--;
            d++;
            int k=it->second;
            ans[cs[i]]=k;
            st.erase(it);
            st.emplace(a[cs[i]].second,k);
        }
    }
    cout<<d<<"\n";
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";



}
