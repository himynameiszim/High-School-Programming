#include<bits/stdc++.h>

using namespace std;

const int mx=1e6+1;

int n,m,a[mx],x,y;

int check(int i)
{
    return a[i]<0?i:a[i]=check(a[i]);
}

void gop(int i,int j)
{
    if(a[i]<a[j])swap(i,j);
        a[i]+=a[j];
        a[j]=i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("DSF.inp","r",stdin);
    freopen("DSF.out","w",stdout);

    for(auto&c:a)c=-1;

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        if(check(x)==check(y))
            cout<<"N\n";
        else
        {
            cout<<"Y\n";
            gop(check(x),check(y));
        }
    }


}
