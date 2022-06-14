#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bit[64],n,s,delta;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("andmax.inp","r",stdin);
    freopen("andmax.out","w",stdout);

    cin>>n;
    for(int b=59;b>=0;b--)
    {
        if(s+3*(1ll<<b)<=n)
        {

            bit[b]=1;
            s+=3*(1<<b);
            delta=n-s;


            for(int i=59;i>=0;i--)
            if(bit[i]==0)
            {
                for(int j=1;j<=3;j++)
                if(delta>=(1ll<<i))delta-=1ll<<i;
            }

            if(delta !=0)
            {
                s-=3*(1ll<<b);
                bit[b]=0;
            }
        }
    }
    cout<<s/3;
}
