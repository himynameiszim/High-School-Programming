//Thầy Hoàng
//
#include<bits/stdc++.h>

using namespace std;

const int M=1e6+6;

int n,m,a[M],mi[M],ma[M],delta;

int check()
{
    deque<int> dqmax,dqmin;
    for(int i=1;i<=n;i++)
    {
        while(!dqmin.empty()&&i-dqmin.front()>=m)dqmin.pop_front();
        while(!dqmin.empty()&&a[dqmin.back()]>=a[i])dqmin.pop_back();
        dqmin.push_back(i);
        mi[i]=a[dqmin.front()];

        while(!dqmax.empty()&&i-dqmax.front()>=m)dqmax.pop_front();
        while(!dqmax.empty()&&-a[dqmax.back()]>=-a[i])dqmax.pop_back();
        dqmax.push_back(i);
        ma[i]=a[dqmax.front()];
    }
    for(int i=m;i<=n;i++)
        if(ma[i]-mi[i]<=delta)return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("LMINMAX.inp","r",stdin);
    //freopen("LMINMAX.out","w",stdout);

    cin>>n>>delta;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=1,r=n+1;
    while(r-l>1)
    {
        m=(l+r)/2;
        if(check())l=m;
        else r=m;
    }
    cout<<m;
}


//segment tree +tknp o(nlog^2n)
/*#include<bits/stdc++.h>

using namespace std;

const int M=1e6+6;

int a[M],n,delta,m;

struct T{
    int mi,ma,hieu;
    T():mi(1e9),ma(-1e9),hieu(0){}
}f[4*M];

T hop(T a,T b)
{
    T ans;
    ans.mi=min(a.mi,b.mi);
    ans.ma=max(a.ma,b.ma);
    ans.hieu=max({a.hieu,b.hieu,abs(ans.mi-ans.ma)});
    return ans;
}

void build(int u,int l,int r)
{
    if(l==r)
    {
        f[u].mi=f[u].ma=a[l];
        f[u].hieu=0;
        return;
    }
    int m=(l+r)/2;
    build(u*2,l,m);
    build(u*2+1,m+1,r);
    f[u]=hop(f[u*2],f[u*2+1]);
}

T query(int L,int R,int u,int l,int r)
{
    if(L>r||l>R)return T();
    if(l<=L&&R<=r)return f[u];
    int m=(L+R)/2;
    return hop(query(L,m,u*2,l,r),query(m+1,R,u*2+1,l,r));
}

int check()
{
    for(int i=1;i<=n-m;i++)
    {
        cout<<query(1,n,1,i,i+m-1).hieu<<" ";
        if(query(1,n,1,i,i+m-1).hieu<=delta)
        {
            cout<<"\n";
            return 1;
        }
    }
    cout<<"\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>delta;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);

    int l=1,r=n+1;
    while(r-l>1)
    {
        m=(l+r)/2;
        cout<<m<<" : ";
        if(check())l=m;
        else r=m;
    }
    cout<<m;
}*/
