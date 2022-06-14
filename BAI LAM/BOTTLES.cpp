//thầy Hoàng

#include<bits/stdc++.h>

using namespace std;

const int M=4e5+20;

deque<int> sub;
int n,a[M],s[M],f[M],h[M],g[M],k,trace[M];
vector<int> vt;
/*
f[i] là số rượu nhiều nhất uống được cho đến chai thứ i
s[i] là tổng từ a[0]->a[i]
for( j=i-k+1->i) f[i]=s[i]-s[j-1]+max(f[1]->f[j-2])
g[i]=max(f[1]->f[i])
f[i]=s[i]-s[j-1]+g[j-2]=s[i]+(g[j-2]-s[j-1])
h[i]=g[i-1]-s[i]
f[i]=s[i]+h[j-1]

để tối ưu hoá bỏ vòng for dùng trượt cửa sổ
cho h[i]
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("BOTTLES.inp", "r", stdin);
    freopen("BOTTLES.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)cin >> a[i];

    for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];

    f[1] = a[1];
    g[1] = 1;
    h[1] = g[0] - s[1];
    sub.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        while (!sub.empty() && (i - sub.front() + 1 >= k))sub.pop_front();
        f[i] = s[i] + h[sub.front() - 1];
        trace[i] = sub.front() - 1;
        if (f[i] > f[g[i - 1]])g[i] = i;
        else g[i] = g[i - 1];
        h[i] = f[g[i - 1]] - s[i];
        while (!sub.empty() && -h[sub.back()] >= -h[i])sub.pop_back();
        sub.push_back(i);
    }
    int bn = n;
    while (n > 0)
    {
        for (int i = n; i > trace[n]; i--)
            vt.push_back(i);
        n = g[trace[n] - 1];
    }
    cout << vt.size() << " " << f[bn] << "\n";
    for (int i = vt.size() - 1; i >= 0; i--)cout << vt[i] << " ";

}
