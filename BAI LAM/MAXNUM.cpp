#include<bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string>vt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("MAXNUM.inp","r",stdin);
    freopen("MAXNUM.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s,vt.push_back(s);
    sort(vt.begin(),vt.end(),[](string s1,string s2){return s1+s2>s2+s1;});
    for(auto&c:vt)cout<<c;
}
