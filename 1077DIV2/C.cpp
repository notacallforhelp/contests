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

   if(is_sorted(A.begin(),A.end()))
   {
        cout << -1 << "\n"; return;
   }

   vector<int> B = A;
   sort(B.begin(),B.end());

   vector<int> temp;

   for(int i=0;i<n;i++)
   {
        if(B[i]!=A[i])
        {
            temp.push_back(A[i]);
        }
   }

   int sm = B[0];
   int bg = B[n-1];

   //sort(temp.begin(),temp.end());

   int ans = 1e15;
   int p = temp.size();

   for(int i=0;i<p;i++)
   {
        int j = max(abs(sm-temp[i]),abs(bg-temp[i]));
        ans = min(ans,j);
   }

   cout << (ans==1e15?-1:ans) << "\n";

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