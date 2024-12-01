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
    
    cout << "Case #"<<caseno<<": "<<" "<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //freopen("prime_subtractorization_input.txt","r",stdin);
    //freopen("prime_output_real.txt","w",stdout);

    int t; cin>>t;

    int caseno = 1;

    while(t--)
    {
        solve(caseno);
        ++caseno;
    }
}