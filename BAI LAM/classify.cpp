#include<bits/stdc++.h>

using namespace std;

int n,m,a[4][109],pl[109];
string s;

int f(char c)
{
    if(c=='A')return 0;
    if(c=='T')return 1;
    if(c=='G')return 2;
    return 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("classify.inp","r",stdin);
    freopen("classify.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            a[f(s[j])][j]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(a[f(s[j])][j])pl[j]=1;
        }
    }

    for(int i=0;i<n;i++)if(!pl[i])cout<<i<<" ";
}
