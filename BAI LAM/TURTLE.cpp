#include<bits/stdc++.h>

using namespace std;

int f[4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>f[0]>>f[1]>>f[2]>>f[3];
    sort(f,f+4);
    cout<<f[2]*f[0];
}
