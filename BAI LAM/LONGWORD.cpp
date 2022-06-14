#include<bits/stdc++.h>

using namespace std;

string s;
int ans,cur;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("LONGWORD.inp","r",stdin);
    freopen("LONGWORD.out","w",stdout);

    getline(cin,s);
    s+=' ';
    for(auto&c:s)
    {
        if(c==' ')
        {
            ans=max(ans,cur);
            cur=0;
        }
        else cur++;
    }
    cout<<ans;
}
