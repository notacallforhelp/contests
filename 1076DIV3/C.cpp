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
   int n,q; cin>>n>>q;
   vector<int> A(n+1);for(int i=1;i<=n;i++) cin>>A[i];
   vector<int> B(n+1); for(int i=1;i<=n;i++) cin>>B[i];

   if(A[n]<B[n]) A[n]=B[n];

   for(int i=n-1;i>=1;i--)
   {
        A[i]=max(A[i+1],B[i]);
   }

   vector<int> pf(n+1);

   for(int i=1;i<=n;i++)
   {
        pf[i]=pf[i-1]+A[i];
   }

   while(q--)
   {
        int l,r; cin>>l>>r;
        int ans = pf[r]-pf[l-1];
        cout << ans << " ";
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