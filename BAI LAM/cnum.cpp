#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxn=1e6+10;

int q, a, b, c[mxn], p[mxn];
ll i;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CNUM.INP", "r", stdin);
    freopen("CNUM.OUT", "w", stdout);
    for (i = 2; i <= 1e6; i++)
    {
        for (ll j = i * i; j <= 1e6; j += i * i)c[j] = 1;
    }

    p[1] = 1;
    for (i = 2; i <= 1e6; i++)
    {
        if (c[i] == 1)p[i] = p[i - 1];
        else p[i] = p[i - 1] + 1;
    }

    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> a >> b;
        cout << p[b] - p[a - 1] << '\n';
    }
}
