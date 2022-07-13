#include<bits/stdc++.h>

using namespace std;

const int M=5e5+25;

vector<int> adj[M];

void process()
{
    int n;
    cin>>n;
    vector<int> flag(n+1);
    for(int i=1;i<=n;i++)
    {
        int s,t;
        cin>>s;
        while(s--)cin>>t,
        adj[i].push_back(t);
    }
    for(int j=0;j<20;j++)
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==j%2)
        {
            int cnt=0;
            for(auto&c:adj[i])
            {
                if(flag[c]==j%2)cnt++;
            }
            if(cnt>1)flag[i]=1-flag[i];
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
    {
        if(flag[i])cout<<i<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(!flag[i])cout<<i<<" ";
    }
}

int main()
{
    freopen("GROUPDIV.inp","r",stdin);
    freopen("GROUPDIV.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}
