#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef long long ll;
typedef long double ld;

void solve()
{   
   int n,s,x; cin>>n>>s>>x;

   vector<int> A(n); for(auto &ele:A) cin>>ele;

   int sum = 0;
   for(auto &ele:A)
   {
        sum += ele;
   }

   if((s-sum)%x==0&&s>=sum)
   {
        cout << "YES\n";
   }
   else
   {
        cout << "NO\n";
   }
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