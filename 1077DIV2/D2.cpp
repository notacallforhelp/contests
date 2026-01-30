#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef long long ll;
typedef long double ld;

int get_first_bit(long long n){
	return 63 - __builtin_clzll(n);
}

void solve()
{   
   int x,y; cin>>x>>y;
    int p = 0;
    int q = 0;

    int mxbit = get_first_bit(max(x,y));

    cout << mxbit << endl;

    int leftx = x;
    int lefty = y;

    int currval = x+y;

    for(int i=mxbit;i>=0;i--)
    {
        int a = abs(x-p-(1ll<<i)) + abs(y-q);
        int b = abs(x-p) + abs(y-q-(1ll<<i));

        cout << p << " " << q << " " << a << " " << b << endl;

        if(a<=currval||b<=currval)
        {
            if(a<=b)
            {
                currval = a;
                p += (1ll<<i);
            }
            else
            {
                currval = b;
                q += (1ll<<i);
            }
        }

        cout << p << " " << q << endl;
    }
   


    cout << p << " " << q << " " << (p&q) << " " << abs(p-x) + abs(q-y) << endl;


}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    // cout << get_first_bit(15ll) << endl;
    // cout << get_first_bit(16ll) << endl;

    int t; cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}