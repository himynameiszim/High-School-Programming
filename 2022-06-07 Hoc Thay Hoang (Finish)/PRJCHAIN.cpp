#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void process()
{
    int n;
    cin>>n;
    vector<array<int,3>> c(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>c[i][0];
        c[i][2]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i][1];
    }
    sort(c.begin()+1,c.end(),[](array<int,3> a, array<int,3> b){if(a[0]-a[1]!=b[0]-b[1])return a[0]-a[1]<b[0]-b[1];else return a[0]<a[1];});
//    for(int i=1;i<=n;i++)
//    {
//        cout<<c[i][2]<<" ";
//    }
//    cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(c[i][0]>=c[i][1])
        {
//            cout<<i<<"\n";
            sort(c.begin()+1,c.begin()+i,[](array<int,3> a, array<int,3> b){return a[0]<b[0];});
//            for(int i=1;i<=n;i++)cout<<c[i][2]<<" ";
//            cout<<"\n";
            sort(c.begin()+i,c.end(),[](array<int,3> a, array<int,3> b){return a[1]>b[1];});
//            for(int i=1;i<=n;i++)cout<<c[i][2]<<" ";
//            cout<<"\n";
            break;
        }
    }
    ll init=0,mn=0;
    for(int i=1;i<=n;i++)
    {
        init-=c[i][0];
        mn=min(init,mn);
//        cout<<init<<" ";
        init+=c[i][1];

    }
//    cout<<"\n";
    cout<<-mn<<"\n";
    for(int i=1;i<=n;i++)cout<<c[i][2]<<" ";

}

int main()
{
    freopen("PRJCHAIN.inp","r",stdin);
    freopen("PRJCHAIN.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
//    cin>>test;
    while(test--)
    {
        process();
    }

}
