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


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int n; cin>>n;

    vector<ll> breaks(n);
    for(int i=0;i<n;i++)
    {
        cin>>breaks[i];
    }
    vector<ll> works(n);

    for(int i=0;i<n;i++)
    {
        cin>>works[i];
    }

    ll m; cin>>m;
    
    ll totaldays = m;

    vector<ll> days(m);
    vector<pair<ll,ll>> workers;

    ll day_ct = 1;

    for(int i=0;i<m;i++)
    {
        ll x, y; cin>>x>>y;
        if(x==1)
        {
            
        }
    }


}