#include<bits/stdc++.h>

using namespace std;

const int Mx=1e5+1;

int a[Mx],b[Mx],n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    b[1]=a[n]-a[n-1];
    b[2]=a[1]-a[n];
    for(int i=1;i<=n;i++)b[i]=a[i-1]-a[i-2];

}
