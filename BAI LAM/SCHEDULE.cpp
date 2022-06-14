//Thầy Hoàng
//Tham lam
//AC
//https://oj.vnoi.info/problem/car
//pod 01/06/2021

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=1e5+5;
const ll mod=1e15;

ll n,dem,ans1,ans2,a[M],b[M],p[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("schedule.inp","r",stdin);
    freopen("schedule.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    iota(p+1,p+1+n,1);

    sort(p+1,p+1+n,[](int i,int j){return a[i]*b[j]>a[j]*b[i];});

    //sử dụng hệ đếm cơ số 1e15
    for(int i=1;i<=n;i++)
    {
        dem+=b[p[i]];
        ans1+=(a[p[i]]*dem)/mod;
        ans2+=(a[p[i]]*dem)%mod;
        ans1+=ans2/mod;
        ans2%=mod;
    }


    if(ans1)cout<<ans1<<setfill('0')<<setw(15)<<ans2<<"\n";
    else cout<<ans2<<"\n";
    for(int i=1;i<=n;i++)
        cout<<p[i]<<" ";


}

