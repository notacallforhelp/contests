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
    int n; cin>>n;
   vector<int> P(n+1);
   int num = n;

   for(int i=n;i>=1;i-=2)
   {
        P[i]=num;
        --num;
   }

   int z = 1;

   for(int i=n-1;i>=1;i-=2)
   {
        P[i]=z;
        ++z;
   }

   for(int i=1;i<=n;i++)
   {
        cout << P[i] << " ";
   }
   cout << "\n";
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