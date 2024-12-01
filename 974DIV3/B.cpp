#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


void solve()
{
    ll n, k; cin>>n>>k;

    ll sum = (n*(n+1)/2)-((n-k)*(n-k+1)/2);

    sum % 2 ==0 ? cout <<"YES\n" : cout <<"NO\n";

    //output %2 ==0 ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
    
}