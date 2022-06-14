//AC

#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

const int M=1e6+6;

typedef pair<int,int> ii;

vector<ii> query;
vector<int> cpr,idx;
int a[M],cnt[M],n,m,ans[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("DQUERY.inp","r",stdin);
    freopen("DQUERY.out","w",stdout);

    cin>>n>>m;
    int s=sqrt(n+m);
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        cpr.push_back(a[i]);
    }
    sort(cpr.begin(),cpr.end());
    cpr.resize(unique(cpr.begin(),cpr.end())-cpr.begin());
    for(int i=1; i<=n; i++)
        a[i]=lower_bound(cpr.begin(),cpr.end(),a[i])-cpr.begin()+1;
    for(int i=0; i<m; i++)
    {
        int l,r;
        cin>>l>>r;
        query.emplace_back(l,r);
        idx.push_back(i);
    }
    sort(idx.begin(),idx.end(),[&](int i,int j){
            if(query[i].F/s!=query[j].F/s)return query[i].F<query[j].F;
            else return query[i].S<query[j].S;
         });
    int pl=0,pr=0,cans=0;
    for(auto&c:idx)
    {
        int l=query[c].F,r=query[c].S;
        while(pr!=r)
        {
            if(r>pr)
            {
                pr++;
                cnt[a[pr]]++;
                if(cnt[a[pr]]==1)cans++;
                if(pr==r)break;
            }
            else
            {
                cnt[a[pr]]--;
                if(!cnt[a[pr]])cans--;
                pr--;
            }
        }
        while(pl!=l)
        {
            if(l>pl)
            {
                cnt[a[pl]]--;
                if(!cnt[a[pl]])cans--;
                pl++;
                if(pl==l)break;
            }
            else
            {
                pl--;
                cnt[a[pl]]++;
                if(cnt[a[pl]]==1)cans++;
            }
        }
        ans[c]=cans;
    }
    for(int i=0;i<m;i++)cout<<ans[i]<<"\n";
}
