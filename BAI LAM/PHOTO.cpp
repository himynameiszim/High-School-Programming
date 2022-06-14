//Thầy Hoàng
//Thầy live chữa hôm 21/06/2021
//Sort
#include<bits/stdc++.h>

using namespace std;

const int M=1e5+5;

int n,k,f[6][M],ans[M];

int check(int x,int y)
{
    int ans=0;
    for(int i=1;i<=5;i++)
        if(f[i][x]<f[i][y])ans++;
    if(ans>=3)return 1;
    else return 0;
}


bool cmp(int x,int y)
{
    return check(x,y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("PHOTO.inp","r",stdin);
    freopen("PHOTO.out","w",stdout);

    cin>>n;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>k;
            f[i][k]=j;//lưu phần tử k trong ảnh i có vị trí là j
        }
    iota(ans+1,ans+1+n,1);
    sort(ans+1,ans+1+n,cmp);

    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
