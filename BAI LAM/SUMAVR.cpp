#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=1e5+5;

ll p[M];
int b,n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b;
        p[i]=b*1ll*i;
        cout<<p[i]-p[i-1]<<" ";
    }
}
