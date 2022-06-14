#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

const int M=1e5+5;

ii a[M],b[M];
vector<int>vec;
int n,pa[M],pb[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("RACE.INP","r",stdin);
    freopen("race.out","w",stdout);


    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i].first;
        b[i].second=i;
    }

    sort(a+1,a+n+1);
    sort(b+1,b+1+n);

    int p=0;
    for(int i=1;i<=n;i++)
    {
        while(p<n&&b[p+1].first<a[i].first)
        {
            ++p;
            vec.push_back(p);
        }
        if(!vec.empty())
        {
            pa[i]=vec.back();
            pb[vec.back()]=i;
            vec.pop_back();
        }
    }
    p=n;
    for(int i=1;i<=n;i++)
        if(pa[i]==0)
        {
            while(p>0&&pb[p]!=0)p--;
            pa[i]=p;
            pb[p]=i;
        }

    for(int i=1;i<=n;i++)cout<<a[i].second<<" "<<b[pa[i]].second<<"\n";

}
