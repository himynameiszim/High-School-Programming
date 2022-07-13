#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll gen(ll l, ll r)
{
    return rng()%(r-l+1)+l;
}
array<int,200> a;

int check()
{
    ifstream cin("out.txt");
    int n;
    ll sum,s=0;
    cin>>n>>sum;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        s+=a[t];
    }
    cout<<sum<<" "<<s<<"\n";
    return sum==s;
}

void process()
{
    ofstream file("inp.txt");
    int n=10,k=gen(2,n);
    file<<n<<" "<<k<<"\n";
    for(int i=1;i<=n;i++)
    {
        file<<(a[i]=gen(1,10))<<" ";
    }
}

int main()
{
//    process();
    int recompile;cin>>recompile;
    if(recompile)
    {
        system("g++ -std=c++14 -O2 -Wall trau.cpp -o trau");
        system("g++ -std=c++14 -O2 -Wall full.cpp -o full");
    }
    for(int test=1;test<=100;test++)
    {
        process();
        clock_t t0=clock();
//        system("trau");
        clock_t t1=clock();
        system("full");
        clock_t t2=clock();
        cout<<"TEST: "<<test<<"   trau: "<<(ld)(t1-t0)/CLOCKS_PER_SEC<<"s     full: "<<(ld)(t2-t1)/CLOCKS_PER_SEC<<"s\n";
//        if(system("fc out.txt ans.txt"))
        if(!check())
        {
            cout<<"WA\n";
            exit(0);
        }
        cout<<"AC\n";
    }
}

