//#include<bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//const int M=4e5+20;
//
//int  n,lmin[M],rmin[M],lmax[M],rmax[M],a[M];
//
//vector<int>vt;
//
//ll ans;
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    freopen("weight.inp","r",stdin);
//    freopen("weight.out","w",stdout);
//    cin>>n;
//    for(int i=1;i<=n;i++)
//        cin>>a[i];
//
//    for(int i=1;i<=n;i++)
//    {
//        while(!vt.empty()&&a[vt.back()]>=a[i])vt.pop_back();
//        if(vt.empty())lmin[i]=0;
//        else lmin[i]=vt.back();
//        vt.push_back(i);
//    }
//
//    vt.clear();
//    for(int i=n;i>=1;i--)
//    {
//        while(!vt.empty()&&a[vt.back()]>a[i])vt.pop_back();
//        if(vt.empty())rmin[i]=n+1;
//        else rmin[i]=vt.back();
//        vt.push_back(i);
//    }
//
//    for(int i=1;i<=n;i++)a[i]=-a[i];
//
//    vt.clear();
//    for(int i=1;i<=n;i++)
//    {
//        while(!vt.empty()&&a[vt.back()]>=a[i])vt.pop_back();
//        if(vt.empty())lmax[i]=0;
//        else lmax[i]=vt.back();
//        vt.push_back(i);
//    }
//
//    vt.clear();
//    for(int i=n;i>=1;i--)
//    {
//        while(!vt.empty()&&a[vt.back()]>a[i])vt.pop_back();
//        if(vt.empty())rmax[i]=n+1;
//        else rmax[i]=vt.back();
//        vt.push_back(i);
//    }
//
//    for(int i=1;i<=n;i++)a[i]=-a[i];
//
//    for(int i=1;i<=n;i++)
//    {
//        ans+=(((ll)i-lmax[i])*(rmax[i]-i)-((ll)i-lmin[i])*(rmin[i]-i))*a[i];
//    }
//
//    cout<<ans;
//}
#include <bits/stdc++.h>

using namespace std;

const int maxN = 4e5 + 10;

int n, a[maxN], L[maxN], R[maxN];
vector <int> st;
long long ans = 0;

void init()
{
    //tính mảng L
    //với mỗi vị trí i, L[i] là phần tử bên trái gần nhất mà > a[i]
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.back()] <= a[i])
        {
            st.pop_back();
        }
        if (st.empty())
        {
            L[i] = 0;
        }
        else
        {
            L[i] = st.back();
        }
        st.push_back(i);
    }
    st.clear();
    //tính mảng R
    //với mỗi vị trí i, R[i] là phần tử bên phải gần nhất mà >= a[i]
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[st.back()] < a[i])
        {
            st.pop_back();
        }
        if (st.empty())
        {
            R[i] = n + 1;
        }
        else
        {
            R[i] = st.back();
        }
        st.push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        //đầu mút l thỏa mãn điều kiện L[i] < l <= i
        //đầu mút r thỏa mãn điều kiện i <= r < R[i]
        ans += (long long)(i - L[i]) * (R[i] - i) * a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("weight.inp","r",stdin);
    freopen("weight.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    init();
    for (int i = 1; i <= n; i++)
    {
        a[i] = -a[i];
    }
    init();
    cout << ans;
}
