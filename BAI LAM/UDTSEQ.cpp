#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=1e5+5;
const int N=1e3+3;

ll cb[N],b,n,m,l,r,dcl,a[M];

/*
Kĩ thuật chia căn
...................................
--->
|.....|.....|.....|.....|.....|...|
   b
tạo 1 biến cộng thêm bao nhiêu cho toàn cục b

|.....|.....|.....|.....|.....|...|
    ^  b[i]  b[i+1] ^
    l               r

chỉ cần thay đổi a[l]->l của b[i] và từ r của b[i+1] đến r
còn lại thêm độ thay đổi cho khối b[i] và b[i+1]

trường hơp xấu nhất là

|.....|.....|
 ^         ^
 l         r
==> chạy xấp xỉ 2 b

cần tính sao cho sự chênh lệch giữa case tốt nhất và xấu nhất là nhỏ nhất

<==> n/b+2b min  <==> n/b+2b>=2sqrt(n/b*2b)

dấu = xảy ra khi n/b=2b <==>b=sqrt(n/2)
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("udtseq.inp","r",stdin);
    freopen("udtseq.out","w",stdout);

    cin>>n>>m;
    int b=sqrt(n/2);
    //cout<<b<<"\n";
    for(int i=0;i<m;i++)
    {
        cin>>l>>r>>dcl;
        if(((l-1+b)/b)*b==((r-1+b)/b)*b)
        {
            for(int i=l;i<=r;i++)a[i]+=dcl;
        }
        else
        {
            for(int i=l;i<=((l-1+b)/b)*b;i++)a[i]+=dcl;
            for(int i=(r/b)*b+1;i<=r;i++)a[i]+=dcl;
            for(int i=(l-1)/b+2;i<=r/b;i++)cb[i]+=dcl;
        }
//        for(int i=1;i<=n;i++)
//        cout<<cb[(i-1+b)/b]<<" ";
//        cout<<"\n\n";
//        for(int i=1;i<=n;i++)
//        cout<<a[i]<<" ";
//        cout<<"\n\n";
//    for(int i=1;i<=n;i++)
//        cout<<a[i]+cb[(i-1+b)/b]<<" ";
//    cout<<"\n";

    }for(int i=1;i<=n;i++)
        cout<<a[i]+cb[(i-1+b)/b]<<" ";
    cout<<"\n";


}
