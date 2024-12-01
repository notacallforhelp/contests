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

void solve(int caseno)
{
    int n; cin>>n;
    vector<pair<ld,ld>> stations(n);

    for(int i=0;i<n;i++)
    {
        cin>>stations[i].first>>stations[i].second;
    }
    ld speed = -1;

    ld maxstart = 0;

    for(int i=0;i<n;i++)
    {
        if(stations[i].second<=maxstart)
        {
            cout << "Case #"<<caseno<<": "<<speed<<endl;
            return;
        }
        maxstart = max(stations[i].first,maxstart);
    }
    for(int i=0;i<n;i++)
    {
        ld localspeed = (i+1)/stations[i].second;
        speed = max(localspeed,speed);
    }

    cout << "Case #"<<caseno<<": "<<speed<<endl;

}

int main()
{
    //freopen("subsonic_subway_input.txt","r",stdin);
    //freopen("subsonic_real.txt","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(8);

    int t; cin>>t;

    int caseno=1;

    while(t--)
    {
        solve(caseno);
        ++caseno;
    }
}