#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef pair<char,int> ci;

vector<ci> vt;

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("BWT.INP","r",stdin);
    freopen("BWT.out","w",stdout);

    while(cin>>s)
    {
        vt.clear();
        for(int i=0;i<s.size();i++)
            vt.emplace_back(s[i],i);
        sort(vt.begin(),vt.end());
        int i=0;
        while(s[i]!='@')i++;
        for(int j=1;j<s.size();j++)
        {
            cout<<vt[i].F;
            i=vt[i].S;
        }
        cout<<"\n";
    }

}
