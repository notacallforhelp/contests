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

    int mxbit = 31;

    int currval = x+y;

    vector<int> bitx(32+1);
    vector<int> bity(32+1);

    for(int i=100;i>=0;i--)
    {
        int a = 1e15;
        int aidx = -1;
        for(int j=0;j<=mxbit;j++)
        {
            if(bitx[j]==0&&bity[j]==0)
            {
                int v = abs(x-p-(1ll<<j)) + abs(y-q);
                if(v<a)
                {
                    a = v;
                    aidx = j;
                }
            }
        }
        // for(int j=mxbit;j>=0;j--)
        // {
        //     if(bitx[j]==0&&bity[j]==0)
        //     {
        //         int v = abs(x-p-(1ll<<j)) + abs(y-q);
        //         if(v<a)
        //         {
        //             a = v;
        //             aidx = j;
        //         }
        //     }
        // }

        int b = 1e15;
        int bidx = -1;

        for(int j=0;j<=mxbit;j++)
        {
            if(bitx[j]==0&&bity[j]==0)
            {
                int v = abs(x-p) + abs(y-q-(1ll<<j));
                if(v<b)
                {
                    b = v;
                    bidx = j;
                }
            }
        }
        // for(int j=mxbit;j>=0;j--)
        // {
        //     if(bitx[j]==0&&bity[j]==0)
        //     {
        //         int v = abs(x-p) + abs(y-q-(1ll<<j));
        //         if(v<b)
        //         {
        //             b = v;
        //             bidx = j;
        //         }
        //     }
        // }

        //cout << p << " " << q << " " << a << " " << b << endl;

        if(a<currval||b<currval)
        {
            if(a<=b)
            {
                currval = a;
                bitx[aidx]=1;
                p += (1ll<<aidx);
            }
            else
            {
                currval = b;
                bity[bidx]=1;
                q += (1ll<<bidx);
            }
        }

        //cout << p << " " << q << endl;
    }
   


    //cout << p << " " << q << " " << (p&q) << " " << abs(p-x) + abs(q-y) << endl;

    cout << p << " " << q << "\n";


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