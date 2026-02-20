#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

const int N = 3e5+10;
vector<int> divisors[N];

void find_divisors()
{
    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
}

void solve()
{   
   int n; cin>>n;
   vector<int> dp(n+1,1e9);
   
   for(int i=0;i<n;i++)
   {
        int x; cin>>x;
        dp[x]=1;
   }

   for(int i=1;i<=n;i++)
   {
        for(auto &divisor:divisors[i])
        {
            dp[i] = min(dp[i],dp[divisor]+dp[i/divisor]);
        }

        cout << (dp[i]==1e9?-1:dp[i]) << " ";
   }
   cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    find_divisors();

    int t; cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}