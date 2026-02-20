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
   int n,h,l; cin>>n>>h>>l;
   vector<int> A(n); for(auto &ele:A) cin>>ele;

   int small = 0;
   int big = 0;

   int sm = min(h,l);
   int bg = max(h,l);

   if(sm==bg)
   {
        for(int i=0;i<n;i++)
        {
            if(A[i]<=sm)
            {
                ++small;
            }
        }

        cout << small/2 << "\n"; return;
   }

   for(int i=0;i<n;i++)
   {
        if(A[i]>sm&&A[i]<=bg)
        {
            ++big;
        }
   }

   for(int i=0;i<n;i++)
   {
        if(A[i]<=sm)
        {
            if(small<big)
            {
                ++small;
            }
            else
            {
                ++big;
            }
        }
   }

   cout << min(small,big) << "\n";
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