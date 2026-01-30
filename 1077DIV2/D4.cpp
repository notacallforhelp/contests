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

   int min = 1e18;
   int p,q;

   auto upd = [&](int _p,int _q)
   {
        if((_p&_q)==0&&(abs(x-_p)+abs(y-_q)<min))
        {
            min = abs(x-_p)+abs(y-_q);
            p = _p;
            q = _q;
        }
   };

   upd(x,y);

   for(int i=29;i>=0;i--)
   {
        if(((x&y)>>i)&1)
        {
            upd((x>>i<<i)+(1ll<<i),y);
            upd(x,(y>>i<<i)+(1ll<<i));
            upd(x>>i<<i,(y>>i<<i)-1);
            upd((x>>i<<i)-1,y>>i<<i);
        }
   }

   cout << p << " " << q << endl;
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