#include<bits/stdc++.h>

using namespace std;

const int x=1e5+1;

int n,a[x],h[x];
bool dg[x];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("DUATHLON.inp","r",stdin);
    freopen("DUATHLON.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i];h[i]=i;}

    sort(h,h+n,[](int i,int j){return a[i]>a[j];});

    //for(int i=0;i<n;i++)cout<<h[i]<<" ";
    //cout<<"\n";
    //giai
    int kq=0,island=0;
    for(int i=0;i<n;i++)
    {
        int mn=h[i];island++;dg[mn]=true;
        if(mn>0&&dg[mn-1])island--;
        //cout<<"isl1="<<island<<"\n";
        if(mn<n-1&&dg[mn+1])island--;
        //cout<<"isl2="<<island<<"\n";
        if(i==n-1||a[mn]!=a[h[i+1]])
        {
            int s=island*2-1;
            //cout<<s<<"\n";
            if(a[0]<a[mn])s++;
            //cout<<s<<"\n";
            if(a[n-1]<a[mn])s++;
            //cout<<s<<"\n";
            kq=max(kq,s);
            //cout<<kq<<"\n";
        }
    }
    cout<<kq-1;

}
