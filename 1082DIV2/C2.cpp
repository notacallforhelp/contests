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

   for(int i=0;i<n;i++)
   {
        set<int> s;
        s.insert(A[i]);
        int ct = 1;
        int ptr = i+1;
        while(ptr<n&&s.count(A[ptr]-1))
        {
            while(*(--s.end())>A[ptr])
            {
                s.erase((--s.end()));
            }
            s.insert(A[ptr]);
            ++ptr;
        }
        output += ct;
        i = ptr-1;
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