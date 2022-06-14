//#include<bits/stdc++.h>
//
//using namespace std;
//
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);
//    freopen("vlon.txt","w",stdout);
//    int n=1e5;
//    cout<<n<<"\n";
//    for(int i=1;i<=n;i++)
//    {
//        cout<<rng()%int(1e7)+1<<" ";
//        if(i%100==0)cout<<"\n";
//    }
//}





#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

const int M=1e7+1000;

int a[M],n,t,ptsnt[M];

vector<int>snt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=2;i<=M;i++)
    {
        if(a[i]==0)
        {
            snt[i]=0;
            a[i]=i;
            snt.push_back(i);
        }
        for(int j=0;j<snt.size()&&snt[j]<=a[i]&&snt[j]*a[i]<=M;j++)a[i*snt[j]]=snt[j];
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        while(t>1)
        {
            snt[a[t]]++;
            t/=a[t];
        }
    }
    int ans=snt.back();
    for(int j=0;j<snt.size();j++)


}



// /*#include<bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int n,t;
//
//double hamlog2(int coso,int somu)
//{
//    if(somu==1)return log2(double(coso));
//    return hamlog2(coso,somu/2)*2+(somu%2)*hamlog2(coso,1);
//}
//
//bool checknt(int n)
//{
//    if(n<2)return 0;
//    for(int i=2;i*i<=n;i++)
//        if(n%i==0)return 0;
//    return 1;
//}
//
//int ans=1e9;
//map<int,pair<int,double> > mp;
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);
//    freopen("findnum.inp","r",stdin);
//    freopen("findnum.out","w",stdout);
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        cin>>t;
//        for(int j=2;j*j<=t;j++)
//            if(t%j==0)
//            {
//                t/=j;
//                mp[j].first++;
//            }
//            if(t>1)mp[t].first++;
//    }
//    for(auto&c:mp)
//    {
//        c.second.second=hamlog2(c.first,int(c.second.first+1));
//    }
//    auto st=mp.begin();
//    for(auto c=mp.begin();c!=mp.end();c++)
//        if(st->second.second>c->second.second)st=c;
//    ans=st->first;
//    for(int i=1;i<=st->second.first;i++)
//        ans*=st->first;
//    int aans=mp.rbegin()->first+1;
//    while(!checknt(aans))aans++;
//
//    cout<<min(aans,ans);
//
//}*/
