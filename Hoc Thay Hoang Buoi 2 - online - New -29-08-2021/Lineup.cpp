#include<bits/stdc++.h>

using namespace std;

const int M=1e5+5;

int a[M],n;
vector<int> vt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("LINEup.inp","r",stdin);
    freopen("LINEup.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        while(vt.size()&&-a[vt.back()]>=-a[i])vt.pop_back();
        if(vt.empty()) cout<<-1<<" ";
        else cout<<vt.back()<<" ";
        vt.push_back(i);
    }
}
