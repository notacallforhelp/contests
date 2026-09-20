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
   int x,y; cin>>x>>y;

   int _x = 0;
   if(y>0)
   {
        _x += 2*y;
   }
   else if(y<0)
   {
        _x -= 4*y;
   }

   if(_x>x)
   {
        cout << "NO\n"; return;
   }

   if(((x-_x)%3)==0||((x-_x)%6)==0)
   {
        cout << "YES\n"; 
   }
   else
   {
        cout << "NO\n";
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