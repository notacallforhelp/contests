#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

void solve()
{
    ll n,q; cin>>n>>q;

    vector<ll> A(n+1);

    map<ll,ll> M;

    for(ll i=1;i<=n;i++)
    {
        cin>>A[i];
        ++M[i*(n-i+1)-1];
    }

    for(int i=1;i<n;i++)
    {
        M[i*(n-i)]+=A[i+1]-A[i]-1;
    }

    

    while(q--)
    {
        ll k; cin>>k;
        cout << M[k] << " ";
    }
    cout << endl;
}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}