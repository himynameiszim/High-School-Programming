//Thầy Hoàng
//chưa có test

#include<bits/stdc++.h>

using namespace std;

const int M=4e6;
const int N=5e3+15;

int c[M],a[N],ans[N],n;

//tính a[i]+a[j]+a[k]=a[x] tại mỗi x
//<==> a[i]+a[j]=a[x]-a[k]

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int k=3;k<n;k++)
    {
        for(int i=1;i<k-1;i++)
        c[a[i]+a[k-1]]++;
        for(int x=k+1;x<=n;x++)
            ans[x]+=c[a[x]-a[k]];
    }

    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";

}
