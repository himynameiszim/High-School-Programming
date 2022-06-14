#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, i, a[100009];
ll k, d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        d += a[i];
    }
    k %= d;
    while (k >= a[i])
    {
        k -= a[i];
        i++;
        i %= n;
    }
    cout << k;
}
