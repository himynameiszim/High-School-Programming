//AC
#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int,int> ii;

const int M=1e5+5;

struct nani
{
    int u,d,id;
    nani():u(0),d(0),id(0){}
    nani(int a,int b,int c):u(a),d(b),id(c){}
};
int n;
vector<nani>vt(M,nani());

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("CLIMBE.inp","r",stdin);
    freopen("CLIMBE.OUT","w",stdout);


    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>vt[i].u;
        vt[i].id=i;
    }
    for(int i=0;i<n;i++)cin>>vt[i].d;
    while(vt.back().id==0&&vt.size()>1)vt.pop_back();
    sort(vt.begin(),vt.end(),[](nani a,nani b)
         {
             return a.u-a.d<b.u-b.d;});
    int i=0;
    while(vt[i].u-vt[i].d<=0&&i<n)i++;
    sort(vt.begin(),vt.begin()+i,[](nani a,nani b){return a.u<b.u;});
    sort(vt.begin()+i,vt.end(),[](nani a,nani b){return a.d>b.d;});

    int tu=0,td=0;
    for(auto&c:vt)
    {
        tu+=c.u;
        td=max(tu,td)+c.d;
    }
    cout<<td<<"\n";
    for(auto&c:vt)cout<<c.id+1<<" ";
}
