#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M=1e5+5;


vector<bool> dachon(M,0);
ll m;
int muachay[M],giamgia[M],n,k,used[M];

struct cmpgiamgia{
    bool operator()(int a,int b)
    {
        return giamgia[a]>giamgia[b];
    }
};

struct cmpmuachay{
    bool operator()(int a,int b)
    {
        return muachay[a]>muachay[b];
    }
};

struct cmpdcl{
    bool operator()(int a,int b)
    {
        return muachay[a]-giamgia[a]>muachay[b]-giamgia[b];
    }
};

priority_queue<int,vector<int>,cmpgiamgia>gg;
priority_queue<int,vector<int>,cmpmuachay>mc;
priority_queue<int,vector<int>,cmpdcl>dochenlech;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k>>m;
    for(int i=0;i<n;i++)
    {
        cin>>muachay[i]>>giamgia[i];
        gg.push(i);
        mc.push(i);
    }
    while(m>=giamgia[gg.top()]||k>0)
    {
        k--;
        m-=giamgia[gg.top()];
        dochenlech.push(gg.top());
        dachon[gg.top()]=1;
        gg.pop();
    }
    int cothechonko=1;
    while(cothechonko)
    {
        while(dachon[mc.top()]==1)mc.pop();

        if(min(muachay[mc.top()],muachay[dochenlech.top()]-giamgia[dochenlech.top()]+giamgia[mc.top()])>m)cothechonko=0;
        else
        {
            if(muachay[mc.top()]<=muachay[dochenlech.top()]-giamgia[dochenlech.top()]+giamgia[mc.top()])
            {
                //dochenlech.push(mc.pop());
                m-=muachay[mc.top()];
                dachon[mc.top()]=1;
                mc.pop();
            }
            else
            {
                m-=muachay[dochenlech.top()]-giamgia[dochenlech.top()]+giamgia[mc.top()];
                dachon[mc.top()]=1;
                mc.pop();
                dochenlech.pop();
            }
        }
    }
    int ans=0;
    for(int i=0;i<M;i++)ans+=dachon[i];
    cout<<ans;

}
