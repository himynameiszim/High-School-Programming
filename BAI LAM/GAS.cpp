// thuật o(n)
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int M=1e6+6;

int n,k,a[M],L,conlai;
ll ans;
vector <ii> vt;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("gas.inp","r",stdin);
    freopen("gas.out","w",stdout);
    /*
    mục đích của biến L
    khi dùng thì luôn dùng cái bé nhất ==> L để đánh dấu cái bé nhất đang dùng nếu dùng hết thì sẽ tăng L
    nhưng cũng có thể thay thế bằng deque để pop_back nhưng cái hết ra
    */
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
    {
        while(vt.size()>L&&vt.back().first>=a[i])
        {
            conlai-=vt.back().second;
            vt.pop_back();
        }
        if(conlai<k)
        {
            vt.emplace_back(a[i],k-conlai);
            conlai=k;
        }
        conlai--;
        vt[L].second--;
        ans+=vt[L].first;
        if(vt[L].second==0)
        {
            L++;
        }
    }
    cout<<ans;
}


