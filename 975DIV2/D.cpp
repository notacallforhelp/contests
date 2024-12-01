 #include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

ll hsh[1e6];

void solve()
{
    int n;cin>>n;
    vector<ll> A(n);

    set<ll> S;

    ll time = n;

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        ++hsh[A[i]];
    }


}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}