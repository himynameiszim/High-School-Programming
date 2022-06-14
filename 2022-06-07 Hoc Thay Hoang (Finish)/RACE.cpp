#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//void process()
//{
//    int n;
//    cin>>n;
//    deque<pii> a(n),b(n);
//    int cnt=0;
//    for(auto&c:a)
//    {
//        cin>>c.F;
//        c.S=++cnt;
//    }
//    cnt=0;
//    for(auto&c:b)
//    {
//        cin>>c.F;
//        c.S=++cnt;
//    }
//    sort(a.begin(),a.end());
//    sort(b.begin(),b.end());
//    swap(a,b);
//    vector<pii> st;
//    for(int i=1;i<=n&&a.size();i++)
//    {
//        while(a.size()&&b.back().F<=a.back().F)
//        {
//            st.push_back(a.back());
//            a.pop_back();
//        }
//        if(a.size())
//        {
//            cout<<b.back().S<<" "<<a.back().S<<"\n";
//            a.pop_back();
//            b.pop_back();
//        }
//    }
//    cnt=0;
//    for(auto &c:b)
//    {
//        cout<<c.S<<" "<<st[cnt++].S<<"\n";
//    }
//}
void process()
{
    int n;
    cin>>n;
    deque<pii> a(n),b(n);
    int cnt=0;
    for(auto&c:a)
    {
        cin>>c.F;
        c.S=++cnt;
    }
    cnt=0;
    for(auto&c:b)
    {
        cin>>c.F;
        c.S=++cnt;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<pii> st;
    ///nếu những con yếu nhất thắng được thì để nó thắng
    ///nếu con yếu nhất thắng nhiều con thì để nó thắng con mạnh nhất

    /**mấu chốt**/
    ///sau khi làm như vậy thì con a mạnh nhất còn lại chỉ có thể hoà hoặc thua con b
    ///không được quyết định ngay mà phải dựa vào tương quan phần còn lại
    vector<pii> aleft;
    while(a.size())
    {
        while(b.size()&&b.front().F<a.front().F)
        {
            st.push_back(b.front());
            b.pop_front();
        }
        if(st.empty())
        {
            aleft.push_back(a.front());
            a.pop_front();
            continue;
        }
        cout<<a.front().S<<" "<<st.back().S<<"\n";
        a.pop_front();
        st.pop_back();
    }
    reverse(st.begin(),st.end());
    for(auto&c:st)b.push_front(c);
    for(auto&c:aleft)
    {
        cout<<c.S<<" "<<b.back().S<<"\n";
        b.pop_back();
    }
}

int main()
{
    freopen("RACE.inp","r",stdin);
    freopen("RACE.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
//    cin>>test;
    while(test--)
    {
        process();
    }

}

