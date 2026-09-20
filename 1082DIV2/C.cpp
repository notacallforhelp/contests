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
   vector<int> A(n); for(auto &ele:A) cin>>ele;

   int output = 0;

   set<int> s;

   for(int i=0;i<n;i++)
   {
        if(s.count(A[i]-1)==0)
        {
            while(!s.empty())
            {
                s.erase(s.begin());
            }
            ++output;
        }
        s.insert(A[i]);
   }

   cout << output << "\n";
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