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

void process()
{
    ofstream file("inp.txt");
    int n=100,m=n;
    file<<n<<" "<<n<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            file<<vector<char>{'.','#'}[min(gen(0,1),gen(0,1))];
        }
        file<<"\n";
    }
}

int main()
{
    process();
    system("g++ -std=c++14 -O2 -Wall trau.cpp -o trau");
    system("g++ -std=c++14 -O2 -Wall full.cpp -o full");
    for(int test=1;test<=100;test++)
    {
        process();
        clock_t t0=clock();
        system("trau");
        clock_t t1=clock();
        system("full");
        clock_t t2=clock();
        cout<<"trau: "<<(ld)(t0-t1)/CLOCKS_PER_SEC<<"s     full: "<<(ld)(t2-t1)/CLOCKS_PER_SEC<<"s\n";
        if(system("fc out.txt ans.txt"))
        {
            cout<<"WA\n";
            exit(0);
        }
        cout<<"AC\n";
    }
}
