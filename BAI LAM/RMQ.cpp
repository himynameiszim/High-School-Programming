// n=1e5 m=1e4 ac spoj
// n=2e5 m=2e5 ac
// n=1e4 m=1e6

#include<bits/stdc++.h>

using namespace std;

const int N=1e6+6;
const int M=1e6+6;

int n,q,a[N],ans[M],m;

struct lmao {
    int l,r,idx;
};

lmao tv[M];

vector<int> vt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("RMQ.inp","r",stdin);
    //freopen("RMQ.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++)cin>>a[i];

    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>tv[i].l>>tv[i].r;
        tv[i].idx=i;
    }

    sort(tv,tv+m,[](lmao j,lmao k){return j.r<k.r;});

    int pt=1;
    for(int i=0;i<m;i++)
    {
        while(pt<=tv[i].r)
        {
            while(!vt.empty()&&a[vt.back()]>=a[pt])vt.pop_back();
            vt.push_back(pt);
            pt++;
        }
        ans[tv[i].idx]=a[*lower_bound(vt.begin(),vt.end(),tv[i].l)];
    }
    for(int i=0;i<m;i++)
        cout<<ans[i]<<"\n";
}
