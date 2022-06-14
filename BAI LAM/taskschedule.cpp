#include<bits/stdc++.h>

using namespace std;

const int M=1e5+5;

int a[M],trc,s,tgianxong[M],n,m;

vector<int> vt[M];

int tinhtgianxong(int object)
{
    if(tgianxong[object]==0)
    {
        if(vt[object].empty())tgianxong[object]= a[object];
        else
        for(auto&c:vt[object])
        {
            tgianxong[object]=max(tinhtgianxong(c)+a[object],tgianxong[object]);
        }
    }
    return tgianxong[object];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)
    {
        cin>>trc>>s;
        vt[s].push_back(trc);
    }

    for(int i=0;i<n;i++)tinhtgianxong(i);

    for(int i=0;i<n;i++)
    cout<<"task "<<i<<" :"<<tgianxong[i]-a[i]<<" : "<<tgianxong[i]<<"\n";
}
