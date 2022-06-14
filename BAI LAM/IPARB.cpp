#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//f[0][0]=-1;
/*
nếu m>v
f[m][v]=f[m-1][v];
else
f[m][v]=f[m][v-m]+f[m-1][v]*/

string f[401][401];
int n;

string plussss(string a,string b)
{
    string g=a;
    for(int i=0;i<a.size();i++)
    {
        g[i]=a[i]+b[i]-48;
        if(g[i]>48+9){g[i]-=10;b[i+1]++;}
    }
    return g;
}

int main()
{
    f[0][0]="000000000000000000000";
    cin>>n;
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)f[i][j]=f[0][0];
    f[0][0]="100000000000000000000";

    for(int m=1;m<=n;m++)
        for(int v=0;v<=n;v++)
    {
        if(m>v)f[m][v]=f[m-1][v];
        else f[m][v]=plussss(f[m][v-m],f[m-1][v]);
    }
    while(f[n][n].back()=='0')f[n][n].pop_back();
    reverse(f[n][n].begin(),f[n][n].end());
    cout<<f[n][n];
}
