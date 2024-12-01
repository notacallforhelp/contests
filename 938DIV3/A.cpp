#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int normalprice=n*a;
    int specialprice=(n/2)*b+(n%2)*a;
    cout << min(normalprice,specialprice)<<endl;
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