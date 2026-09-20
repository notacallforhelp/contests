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
   vector<int> A(n+1);
   vector<pair<int,int>> st;

   for(int i=1;i<=n;i++)
   {
        cin>>A[i];
   }

   int output = 0;
   int current_sum = 0;

   for(int i=n;i>=1;i--)
   {
        while(!st.empty()&&st.back().first==A[i]+1)
        {
            current_sum -= (n-st.back().second+1);
            st.pop_back();
        }
        st.push_back({A[i],i});
        current_sum += (n-i+1);

        output += current_sum;
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