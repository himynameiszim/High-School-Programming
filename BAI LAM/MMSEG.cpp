#include<bits/stdc++.h>

using namespace std;
int t,ma,mi,a[1000009],n,pmi,pma,ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("MMSEG.inp","r",stdin);
    freopen("MMSEG.out","w",stdout);
    cin>>t;
    for(int k=0;k<t;k++)
    {
        cin>>n;
        ma=n+1;
        mi=0;
        ans=1e9;
        pmi=mi;pma=ma;
        a[0]=1e9+9;a[n+1]=-1e9-9;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<a[mi]){mi=i;pmi=i;}
            if(a[i]>a[ma]){ma=i;pma=i;}
            if(a[i]==a[mi])
            {//cout<<abs(ma-mi)<<" " <<abs(i-ma)<<"  g\n";
                if(abs(ma-mi)>abs(i-ma))mi=i;
                else pmi=i;

            }
            if(a[i]==a[ma])
            {
                if(abs(mi-i)<abs(mi-ma))ma=i;
                else pma=i;
            }
            if(abs(pmi-ma)<abs(mi-ma))mi=pmi;
            if(abs(pma-mi)<abs(ma-mi))ma=pma;
            if(abs(pma-pmi)<=min(abs(mi-ma),abs(pmi-ma))){ma=pma;mi=pmi;}
            ans=abs(ma-mi);
            //cout<<mi<<"   "<<ma<<"   "<<pmi<<"   "<<pma<<"   "<<a[ma]<<"   "<<a[mi]<<"\n";
        }
        cout<<ans+1<<"\n";
    }
}
