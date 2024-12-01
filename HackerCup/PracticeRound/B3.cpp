#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve(int caseno)
{
    ll n, p; cin>>n>>p;

    long double probab = p/100.0;
    long double arg = exp(probab,n-1);
    arg = n_root_(arg,n);
    
    cout << (arg-probab)*100<< endl;

}

int main()
{
    int t;cin>>t;
    int caseno=1;

    while(t--)
    {
        solve(caseno);
        ++caseno;
    }
}