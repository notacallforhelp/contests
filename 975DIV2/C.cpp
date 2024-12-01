#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

void solve()
{
    ll n, k; cin>>n>>k;

    vector<ll> A(n);

    ll cards = 0;

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        cards+=A[i];
    }

    ll mx = *max_element(A.begin(),A.end());


    for(ll s=n;s>=1;s--)
    {
        ll totalcanhave = cards + k;

        ll d_mult_s = totalcanhave - (totalcanhave%s);

        if(d_mult_s<cards) continue;

        ll d = d_mult_s/s;

        if(d>=mx)
        {
            cout << s << endl;
            return;
        }
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