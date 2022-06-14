#include<bits/stdc++.h>

using namespace std;

const int x=101;

int a[x], f[x][x*x*2], n,k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("expression.inp","r",stdin);
    freopen("expression.out","w",stdout);
    cin>>n>>k;
    k+=1e4;
    for(int i=1;i<=n;i++)cin>>a[i];
    f[1][int(1e4)+a[1]]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=2e4;j++)
        if(f[i-1][j]==1)
        {
            //mảng f sẽ đánh dấu nếu 1 là đã tính đến
            f[i][j+a[i]]=1;
            f[i][j-a[i]]=1;
        }
    //mảng f sẽ đánh dấu nếu 1 thì là có chọn để tính nếu đánh dấu là 2 thì vừa làm phép trừ nếu 3 là vừa làm phép cộng
    int tk=k;
    for(int i=n;i>1;i--)
    {
        if(f[i-1][tk+a[i]]==1){f[i-1][tk+a[i]]=2;tk+=a[i];}
        else if(f[i-1][tk-a[i]]==1){f[i-1][tk-a[i]]=3;tk-=a[i];}
    }
    for(int i=1;i<n;i++)
        for(int j=0;j<=2e4;j++)
        if(f[i][j]>1)
    {
        if(f[i][j]==2)cout<<"-";
        else cout<<"+";
        break;
    }
}
