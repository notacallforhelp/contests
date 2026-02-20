#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

void solve()
{   
   int n; cin>>n;
   vector<int> A(n+1);
   for(int i=1;i<=n;i++) cin>>A[i];

   vector<int> vis(n+1);

   for(int i=1;i<=n;i++)
   {
        if(vis[i]) continue;

        set<int> s;
        for(int j=i;j<=n;j*=2)
        {
            s.insert(j);
        }
        for(int j=i;j<=n;j*=2)
        {
            vis[j]=1;
            if(s.count(A[j]))
            {
                s.erase(A[j]);
            }
        }
        if(!s.empty())
        {
            cout << "NO\n";
            return;
        }
   }

   cout << "YES\n";
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