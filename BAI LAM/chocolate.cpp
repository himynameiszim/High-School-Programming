#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans=1;

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("chocolate.inp","r",stdin);
    freopen("chocolate.out","w",stdout);
    cin>>s;
    while(s.back()!='X')s.pop_back();
    reverse(s.begin(),s.end());
    while(s.back()!='X')s.pop_back();
    int d=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='X')
        {
            ans*=d;
            d=1;
        }
        else d++;
    }
    cout<<ans;
}
