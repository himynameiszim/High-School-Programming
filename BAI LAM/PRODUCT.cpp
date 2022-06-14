#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod=123456789;

vector<ll>vt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("PRODUCT.inp","r",stdin);
    freopen("PRODUCT.out","w",stdout);

    int test=1;
    cin>>test;
    while(test--)
    {
        vt.clear();
        int n,t,k;
        ll ans=1;
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>t,vt.push_back(t);
        sort(vt.begin(),vt.end());
        if(vt.back()<=0)
        {
            //cout<<1<<" ";
            if(k&1)
            {
                for(int i=(int)vt.size()-1;i>=n-k;i--)
                    ans=ans*((vt[i]+mod*mod)%mod)%mod;
            }
            else
            {
                for(int i=0;i<k;i++)
                    ans=ans*((vt[i]+mod*mod)%mod)%mod;
            }
            cout<<ans;
        }
        else
        {
            //cout<<2<<" ";
            int idplus=vt.size(),idminus=-1;
            if(k&1)idplus--,k--;
            while(idplus-2>=0&&vt[idplus-2]&&k-2>=0)
            {
                idplus-=2;
                k-=2;
            }
            while(idminus+2<vt.size()&&k-2>=0&&vt[idminus+2])
            {
                idminus+=2;
                k-=2;
            }
            if(k)
            {
                cout<<0;
            }
            else
            {
                while(idminus+2<vt.size()&&idplus+2<=vt.size()&&vt[idminus+1]*vt[idminus+2]>=vt[idplus+1]*vt[idplus])
                {
                    idminus+=2;
                    idplus+=2;
                }
                while(idminus-2>=-1&&idplus-2>=0&&vt[idminus]*vt[idminus-1]<=vt[idplus-2]*vt[idplus-1])
                {
                    idminus-=2;
                    idplus-=2;
                }
                for(int i=0;i<=idminus;i++)
                    ans=ans*((vt[i]+mod*mod)%mod)%mod;
                for(int i=idplus;i<vt.size();i++)
                    ans=ans*((vt[i]+mod*mod)%mod)%mod;
                cout<<ans;
            }
        }
        cout<<"\n";
    }
}
