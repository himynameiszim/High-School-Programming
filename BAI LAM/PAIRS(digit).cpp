//Thầy Hoàng
//Chữ
#include<bits/stdc++.h>

using namespace std;

string s[22];
int f[22],n,k,ans;
//Cách 1
/*queue<int>q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;

    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        while(!q.empty()&&q.front()<i-k)
        {
            f[s[q.front()].size()]--;
            q.pop();
        }
        ans+=f[s[i].size()];
        f[s[i].size()]++;
        q.push(i);
    }

    cout<<ans;

}*/
//Cách 2

queue<int> q[22];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        while(!q[int(s[i].size())].empty()&&q[int(s[i].size())].front()<i-k)q[int(s[i].size())].pop();
        ans+=q[s[i].size()].size();
        q[s[i].size()].push(i);
    }
    cout<<ans;
}
