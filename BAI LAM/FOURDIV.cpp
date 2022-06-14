#include<bits/stdc++.h>

using namespace std;

const int M=3e6+18;

int l[M];

vector<int>snt;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("fourdiv.inp","r",stdin);
    freopen("fourdiv.out","w",stdout);

    for(int i=2;i<3e6;i++)
    {
        if(!l[i])
        {
            snt.push_back(i);
            l[i]=i;
        }
        for(int j=0;j<(int)snt.size()&&snt[j]<=l[i]&&(ll)snt[j]*i<M;j++)
            l[snt[j]*i]=snt[j];
    }
    int test;
    cin>>test;
    while(test--)
    {
        int dist;
        cin>>dist;
        ll d=*lower_bound(snt.begin(),snt.end(),1+dist);
        ll dd=*lower_bound(snt.begin(),snt.end(),d+dist);
        cout<<dd*d<<"\n";

    }
}
