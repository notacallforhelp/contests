#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    int n; cin>>n;
    vector<ll> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    ll cnt = 0;
    ll global = 0;
    ll local = 0;
    ll idx=-1;
    if(n==1)
    {
        cout << 1 << " " << 0 << endl;
        return;
    }

    if(A[0]>A[1])
    {
        global=A[0];
        ++cnt;
        idx=0;
    }

    for(int i=1;i<=n-2;i++)
    {
        if(A[i]>A[i-1]&&A[i]>A[i+1])
        {
            ++cnt;
            local = A[i];
        }
        if(global<local)
        {
            global = local;
            idx = i;
        }
    }

    if(A[n-1]>A[n-2])
    {
        ++cnt;
        if(global<A[n-1])
        {
            global=A[n-1];
            idx=n-1;
        }
    }
    //cout << global << endl;
    cout << cnt << " " << idx << endl;
}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}