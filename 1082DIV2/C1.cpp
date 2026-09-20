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
   stack<int> st;
   int n; cin>>n;
   vector<int> A(n);

   for(int i=0;i<n;i++)
   {
        cin>>A[i];
   }

   for(int i=n-1;i>=0;i--)
   {
        while(!st.empty()&&st.top()==A[i]+1)
        {
            st.pop();
        }
        st.push(A[i]);
   }

   int ct = 0;
   while(!st.empty())
   {
        st.pop();
        ++ct;
   }

   cout << ct << "\n";
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