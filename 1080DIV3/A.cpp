#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

void solve()
{   
   int n; cin>>n;
   vector<int> A(n); for(auto &ele:A) cin>>ele;
   for(auto &ele:A)
   {
        if(ele==67)
        {
            cout << "YES\n"; return;
        }
   }

   cout << "NO\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}