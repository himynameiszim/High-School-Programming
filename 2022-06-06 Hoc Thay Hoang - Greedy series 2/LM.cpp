#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=1e6+6;

int f[M],hdv[M];

void process()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<=n;i++)f[i]=-1;
    for(auto&c:s)c-='0';
    sort(s.begin(),s.end());
    queue<array<int,2>> q;///chia n du - hang don vi
    for(auto&c:s)if(c)
    {
        q.push({c%n,c});
        f[c%n]=0;
        hdv[c%n]=c;
        if(f[0]!=-1)break;
    }
    while(q.size())
    {
        array<int,2> u=q.front();
        q.pop();
        for(auto&c:s)
        {
            if(f[(u[0]*10+c)%n]==-1)
            {
                f[(u[0]*10+c)%n]=u[0];
                hdv[(u[0]*10+c)%n]=c;
                q.push({(u[0]*10+c)%n,c});
            }
        }
    }
    if(f[0]==-1)
    {
        cout<<0;
        return ;
    }
    int d=0;
    string ans;
    while(f[d])
    {
        ans+=char(hdv[d]+'0');
        d=f[d];
    }ans+=char(hdv[d]+'0');
    reverse(ans.begin(),ans.end());
    cout<<ans;
}

int main()
{
    freopen("LM.inp","r",stdin);
    freopen("LM.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}
