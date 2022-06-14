#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x,y,d;

void extendedEuclid(ll a,ll b)
{
    if(b==0)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        extendedEuclid(b,a%b);
        ll temp=x;
        x=y;
        y=temp-ll(a/b)*y;
    }
}

void process()
{
    ll a,b,c,ax=1,by=1,cz=1;

    cin>>a>>b>>c;

    if(a==0&&b==0)
    {
        if(c==0)cout<<0<<" "<<0<<"\n";
        else cout<<0<<"\n";
        return;
    }
    if(a<0)
    {
        a=abs(a);
        ax=-1;
    }
    if(b<0)
    {
        b=abs(b);
        by=-1;
    }
    if(c<0)
    {
        c=abs(c);
        cz=-1;
    }
    if(c%__gcd(a,b))
    {
        cout<<0<<"\n";
        return;
    }
    cz*=c/__gcd(a,b);
    extendedEuclid(a,b);
    cout<<x*ax*cz<<" "<<y*by*cz<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test=1;
    cin>>test;
    while(test--)
    {
        process();

    }

}
