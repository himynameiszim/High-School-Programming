//Thầy Hoàng
//21/06/2021
//Chặt nhị phân khoảng cách rồi dfs cây khung
//AC
//ko có test nhưng đã chấm sever thầy

#include<bits/stdc++.h>

using namespace std;

const int M=5005;

int n,x[M],y[M],flag[M],base[M][M],m,ans[M];
vector<int> vt;

void dfs(int u)
{
    for(int i=1;i<=n;i++)
        if(!flag[i]&&base[u][i]<=m&&u!=i)
        {
            flag[i]=u;
            dfs(i);
        }
}

void trace()
{
    int c=n;
    while(ans[c]!=c)
    {
        vt.push_back(c);
        c=ans[c];
    }
    vt.push_back(1);
    reverse(vt.begin(),vt.end());
    for(auto&c:vt)cout<<c<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("DESert.inp","r",stdin);
    freopen("DESert.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];

    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            base[j][i]=base[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);

    int l=0,r=4e6+24;
    while(r-l>1)
    {
        fill(flag,flag+n+1,0);
        m=(l+r)/2;
        flag[1]=1;
        dfs(1);
        if(flag[n])
        {
            for(int i=1;i<=n;i++)ans[i]=flag[i];
            r=m;
        }
        else l=m;
    }
    cout<<r<<"\n";
    trace();
}
