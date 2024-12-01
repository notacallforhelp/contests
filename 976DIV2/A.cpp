#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

void solve()
{
    ll n, k; cin>>n>>k;

    ll ct = 0;

    ll prod = 1;

    if(k==1)
    {
        cout << n << endl;
        return;
    }

    while(prod*k<=n)
    {
        prod=prod*k;
    }

    //cout << prod << endl;

    while(n&&prod>0)
    {
        ct += n/prod;
        n = n - (n/prod)*prod;
        //cout << n << endl;
        while(prod>0&&prod>n)
        {
            prod = prod/k;
        }
    }
    cout << ct << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}