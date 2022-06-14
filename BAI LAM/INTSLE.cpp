#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a1,a2,b1,b2,c1,c2;

void process()
{
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    if(a1*)
    if(a1*b2==a2*b1)
    {
        if(a1*c2==a2*c1)cout<<"INFINITE\n";
        else cout<<"NO SOLUTION\n";
    }
    else
    {
        int d=1;
        if(a1*a2!=0)d=__gcd(abs(a1),abs(a2));
        b1*=a2/d;
        a2*=a1/d;
        b2*=a1/d;
        c2*=a1/d;
        a1=a2/d;
        c2-=c1;
        b2-=b1;
        if(c2%abs(b2)!=0)cout<<"NO SOLUTION\n";
        else
        {
            ll y=c2/b2;
            if(y*b1)
        }
    }
}
int main()
{
    ios_base::syns_with_stdio(false);
    cin.tie(0);



}
