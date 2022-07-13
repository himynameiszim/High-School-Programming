#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N=1e5+5;

int a[N],dp[N],s[N];

template<typename T>
bool maximize(T &a, T b ){return a<b?a=b,1:0;}

void process()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j+k>=i;j--)
        {
            dp[i]=max(dp[i],dp[j]+s[i]-s[j+1]);
//            if(dp[])
        }
//        cout<<dp[i]<<" ";
    }
//    cout<<"\n";
    cout<<dp[n];
}

int main()
{
//    freopen("PEACH.inp","r",stdin);
//    freopen("PEACH.out","w",stdout);
    freopen("inp.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    process();
}

