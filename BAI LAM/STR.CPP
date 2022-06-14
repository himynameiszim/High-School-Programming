#include<bits/stdc++.h>

using namespace std;

string s;
int ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("STR.inp","r",stdin);
    freopen("STR.out","w",stdout);


    ///các chữ A ở cuối là vô nghĩa
    ///thêm vào để tránh trường hợp AAB ...
    cin>>s;
    s='0'+s;
    s+='A';
    for(int i=1; i<s.size()-2; i++)
        if(s[i]==s[i+2]&&s[i]!=s[i+1])
        {
            s[i+1]=s[i];
            ans++;
        }
    while(s.back()=='A')s.pop_back();
    for(int i=1; i<s.size(); i++)
        ans+=(s[i]!=s[i-1]);
    cout<<ans;
}
