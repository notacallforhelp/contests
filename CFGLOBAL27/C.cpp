#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


typedef long long int ll;
typedef long double ld;

//ordered_sets
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//struct for range 
struct range
{
    ll l,r,index;
    bool operator < (const range &other) const
    {
        if(l==other.l)
            return r>other.r;
        return l < other.l;
    }
};

/*binary search template

while(hi-low>0)
    {
        ll mid = (low+hi)/2;
        ll products = 0;
        for(int i=0;i<n;i++)
        {
            products += min(mid/A[i],(ll)1e9);
        }
        if(products>=k)
        {
            if(mid<answer)
            {
                answer = mid;
            }
            hi = mid;
        }
        else
        {
            low = mid+1;
        }
    }

FOR SIMULATING ALL CELLS THAT SHARE A WALL WITH CURRENT CELL, GRID IS OF SIZE N*M

int dx[]={-1,0,+1,0};
int dy[]={0,-1,0,+1};

inline bool in(int i,int j){
    return (0<=i&&i<n&&0<=j&&j<m);
}

*/

void solve()
{
    ll n; cin>>n;
    if(n%2!=0)
    {
        cout << n << endl;
        for(int i=1;i<=n;i++)
        {
            if(i==1||i==3||i==(n-1)||i==n)
            {
                continue;
            }
            cout << i << " ";
        }
        cout << 1 << " " << 3 << " " << n-1 << " "<<n << endl;
        return;
    }
    else
    {
        if(n==6)
        {
            cout << "7" << endl;
            cout << "1 2 4 6 5 3" << endl;
        }
        else
        {
            int upperlimit=1;
            while(upperlimit<=n)
            {
                upperlimit = upperlimit <<1 ;
            }
            cout << upperlimit-1 << endl;
            int a = upperlimit/2 -1;
            int b = a-1;

            for(int i=1;i<=n;i++)
            {
                if(i==a||i==b||i==n||i==1||i==3)
                {
                    continue;
                }
                cout << i << " ";
            }
            cout << 1 << " " << 3 << " " << b << " " << a << " " << n << endl;
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}