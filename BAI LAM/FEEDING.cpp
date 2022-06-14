#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;


const int M=1e5+5;

vector<int> vt;
ll a[M],p[M],price=1e9,n,ans;
//ko hạn chế số thức ăn mua nên cứ mua vô hạn trước rồi tính tiền khi dùng
//sẽ dùng và tính tiền ở ngày phải trả ít tiền nhất
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
    {
        price=min(price,p[i]);
        ans+=a[i]*price;
    }
    cout<<ans<<"\n";
}
