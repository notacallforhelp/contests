#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

void solve()
{   
   int n; cin>>n;
   vector<int> A(n);
   vector<int> B(n);
   vector<int> C(n);

   for(int i=0;i<n;i++)
   {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            int _a = A[i]-A[j];
            int _b = B[i]-B[j];
            int _c = C[i]-C[j];
            
        }
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