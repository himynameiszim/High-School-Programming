#include<bits/stdc++.h>

using namespace std;

string s;
vector<int> vt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')vt.push_back(i);
        else
        {
            cout<<vt.back()<<" ";
            vt.pop_back();
        }
    }
}
