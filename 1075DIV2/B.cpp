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
   int n,x; cin>>n>>x;
   vector<vector<int>> A(n,vector<int>(3,0));

   int freej = 0;

   int highest = -1e18;

   for(int i=0;i<n;i++)
   {
        cin>>A[i][0]>>A[i][1]>>A[i][2];

        freej += (A[i][1]-1)*(A[i][0]);
        highest = max(highest,(A[i][1])*A[i][0]-A[i][2]);
   }

   if(freej>=x)
   {
        cout << 0 << "\n"; return;
   }

   if(highest<=0)
   {
        cout << -1 << "\n"; return;
   }

   cout << (x-freej+highest-1)/highest << "\n";

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

