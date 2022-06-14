#include <bits/stdc++.h>

/*
f[m][v]: v là số n cần phân tích m là số lớn nhất trong những số n có thể phân tích ra
if(m>v)f[m][v]=f[m-1][v];
if(a[m]<v)f[m][v]=0;
else f[m][v]=f[m-1][v-m]+f[m-1][v]
*/

using namespace std;

const int mx=5e3+10;
const int inf=2e9;

int f[mx][mx], a[mx], n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("IPARD.inp","r",stdin);
    freopen("IPARD.out","w",stdout);
    for(int i=1;i<=5e3;i++)a[i]=a[i-1]+i;
    cin>>n;
    f[0][0]=1;
    for(int m=1;m<=n;m++)
        for(int v=0;v<=n;v++)
        if(m>v)f[m][v]=f[m-1][v];
        else
        {
            if(a[m]<v)f[m][v]=0;
            else f[m][v]=(f[m-1][v-m]+f[m-1][v])%123456789;
        }
    cout<<f[n][n];
}
