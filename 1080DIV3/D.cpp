#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

void solve()
{   
   int n; cin>>n;
   vector<int> F(n+1);
   for(int i=1;i<=n;i++) cin>>F[i];

   int sumall = (F[1]+F[n])/(n-1);

   vector<int> output;

   int sumsofar = 0;

   for(int i=2;i<=n;i++)
   {
        int ele = (F[i]-F[i-1]+sumall)/2 - sumsofar;
        output.push_back(ele);
        sumsofar += ele;
   }

   output.push_back(sumall-sumsofar);

   for(auto &ele:output)
   {
        cout << ele << " ";
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