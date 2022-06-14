//Thầy Hoàng
//chưa chấm,ko có test chỉ thử test đề
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef pair<int,int> ii;

const int M=1e5+5;

int n,l,r,sophong=1;
vector<int>vt[M],cs;
multiset<ii> info;
vector<ii> vtii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("ROOMS.inp","r",stdin);
    freopen("ROOMS.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>l>>r;
        vtii.push_back(ii(l,r));
        cs.push_back(i);
    }
    sort(cs.begin(),cs.end(),[](int a,int b){if(vtii[a].S!=vtii[b].S)return vtii[a].S<vtii[b].S;else return vtii[a].F<vtii[b].F;});

    info.insert(ii(-1,1));

    for(int i=0;i<n;i++)
    {
        auto id=info.upper_bound(ii(vtii[cs[i]].F,1e9));
        if(id==info.begin())
        {
            sophong++;
            vt[sophong].push_back(cs[i]);
            info.insert(ii(vtii[cs[i]].S,sophong));
        }
        else
        {
            id--;
            ii temp=*id;
            info.erase(id);
            vt[temp.S].push_back(cs[i]);
            temp.F=vtii[cs[i]].S;
            info.insert(temp);
        }
    }

    cout<<sophong<<"\n";
    for(int i=1;i<=sophong;i++)
    {
        for(int j=0;j<vt[i].size();j++)cout<<vt[i][j]+1<<" ";
        cout<<"\n";
    }
}
