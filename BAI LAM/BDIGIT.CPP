#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull gg=9223372036854775808*2-1;

ull n,i,g=1,t;

int sldn,luu=1;//so lan dao nguoc

// gg=2^64-1==>gg/2=2^63-1
//=>>lis do xuaats hieenj bieens luu

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("BDIGIT.inp","r",stdin);
    freopen("BDIGIT.out","w",stdout);
    cin>>t;
    for(int z=0;z<t;z++)
    {
        sldn=0;
        g=gg;
        luu=1;
        cin>>n;
        while(n>0)
        {
            g=g/2+luu;
            luu=0;
            if(n>=g)
            {
                sldn++;
                n-=g;
            }
        }
        cout<<sldn%2<<"\n";
    }

}
