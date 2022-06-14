#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=3e5+15;

string s;

int r[M],b[M],ans,n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("MARBLES.inp","r",stdin);
    freopen("MARBLES.out","w",stdout);

    cin>>s;
    n=s.size();
    s='0'+s+s+s;


    for(int i=1; i<int(s.size()); i++)
    {
        r[i]=r[i-1]+(s[i]=='r');
        b[i]=b[i-1]+(s[i]=='b');
    }
    if((ll)b[n]*r[n]==0)
    {
        cout<<n;
        return 0;
    }

    for(int i=n+1; i<=2*n; i++)
    {
        int l;
        int L=0,R=n;
        while(R-L>1)
        {
            int m=(L+R)/2;
            if((r[i]-r[i-m])*(b[i]-b[i-m])==0)L=m;
            else R=m;
        }
        l=L;
        L=0;
        R=n-l;
        if((r[i+R]-r[i])*(b[i+R]-b[i])==0)
        {
            cout<<n;
            return 0;
        }

        while(R-L>1)
        {
            int m=(L+R)/2;
            if((r[i+m]-r[i])*(b[i+m]-b[i])==0)L=m;
            else R=m;
        }
        ans=max(ans,l+L);
    }
    ///khi chặt ntn thì ans có thể sẽ > n (wrbbwb)->wr bbwbw
    cout<<ans;
}
