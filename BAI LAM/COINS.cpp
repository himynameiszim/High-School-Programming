#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=1e5+5;
const int mod=123456789;

ll f[M],trace[M],temp[M],k;
map<int,int>mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("coins.inp","r",stdin);
    freopen("coins.out","w",stdout);

    cin>>k;

    f[0]=1;
    for(int i=1;i<=100&&i*i<=k;i++)
        for(int j=0;j<k;j++)
            if(j+i*i<=k)
            {
                if(f[j])
                {
                    f[j+i*i]=(f[j+i*i]+f[j])%mod;
                }
                //vì có đồng 1 xu nên có thể trả tất cả các giá trị
                if(!trace[j+i*i])
                {
                    trace[j+i*i]=trace[j]+1;
                    temp[j+i*i]=i;
                }
                else
                {
                    if(trace[j+i*i]>trace[j]+1)
                    {
                        trace[j+i*i]=trace[j]+1;
                        temp[j+i*i]=i;
                    }
                }
            }
    cout<<f[k]<<"\n"<<trace[k]<<"\n";
    while(k>0)
    {
        mp[temp[k]]++;
        k-=temp[k]*temp[k];
    }

    for(auto&c:mp)
    {
        cout<<c.second<<" "<<c.first<<"\n";
    }







}
