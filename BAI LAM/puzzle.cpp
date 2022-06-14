#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

const int mxn=1e3+10;

int n, m;
stack<ii> ngang[100], doc[100];
char a[mxn][mxn];
string ms;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("PUZZLE.INP", "r", stdin);
    freopen("PUZZLE.OUT", "w", stdout);
    cin >> n >> m;
    bool ok = true, reok = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int j = 1; j <= m; j++)doc[a[1][j]].push(ii(1, j));
    for (int i = 1; i <= n; i++)ngang[a[i][1]].push(ii(i, 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '#')
            {
                if (j < m)ngang[a[i][j + 1]].push(ii(i, j + 1));
                if (i < n)doc[a[i + 1][j]].push(ii(i + 1, j));
            }
    int ngangmax = 65;
    for (int k = 65; k < 65 + 27; k++)
    {
        if (!ngang[k].empty())ngangmax = k;
    }

    int docmax = 65;
    for (int k = 65; k < 65 + 27; k++)
    {
        if (!doc[k].empty())docmax = k;
    }

    while (!ngang[ngangmax].empty())
    {
        ii t = ngang[ngangmax].top();
        ngang[ngangmax].pop();
        int i = t.first, j = t.second;
        string s;
        while (a[i][j] != '#')
        {
            s += a[i][j];
            j++;
            if (j > m)break;
        }
        if (s > ms)ms = s;
    }
    while (!doc[docmax].empty())
    {
        ii t = doc[docmax].top();
        int i = t.first, j = t.second;
        doc[docmax].pop();
        string s;
        while (a[i][j] != '#')
        {
            s += a[i][j];
            i++;
            if (i > n)break;
        }
        if (s > ms)ms = s;
    }
    cout << ms;
}
