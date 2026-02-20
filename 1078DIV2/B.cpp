#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;



void solve()
{   
   int n,x,y; cin>>n>>x>>y;

   vector<int> A(n); for(auto &ele:A) cin>>ele;
   vector<int> B(n);

   int s = 0;

   for(int i=0;i<n;i++)
   {
        B[i] = (A[i]/x)*y;
        s += B[i];
   }

   int output = 0;

   for(int i=0;i<n;i++)
   {
        int loc = s-B[i]+A[i];
        output = max(output,loc);
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