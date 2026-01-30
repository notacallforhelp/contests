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

   int p = 0; 
   int q = 0;

//    for(int i=0;i<31;i++)
//    {
//         if(((1ll<<i)&x)&&((1ll<<i)&y))
//         {
//             p += (1ll<<i);
//         }
//         else if(((1ll<<i)&x))
//         {
//             p += (1ll<<i);
//         }
//         else if(((1ll<<i)&y))
//         {
//             q += (1ll<<i);
//         }
//    }
    p = 

   cout << p << " " << q << " " << abs(p-x) + abs(q-y) <<" "<<(p&q)<< endl;
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