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

*/

bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    int mn_a = min(a.first,a.second);
    int mx_a = max(a.first,a.second);
    int mn_b = min(b.first,b.second);
    int mx_b = max(b.first,b.second);
    //cout << mn_a << " " << mx_a << endl;
    //cout << mn_b << " " << mx_b << endl;
    /*if(mn_a<mn_b)
    {
        return mn_a < mn_b;
    }
    else if(mn_b < mn_a)
    {
        return mn_b < mn_a;
    }
    else        //if mn_b==mn_a
    {
        if(mx_a<=mx_b)
        {
            return mx_a<=mx_b;
        }
        else
        {
            return mx_b < mx_a;
        }
    }*/

    if (mn_a != mn_b)
    {
        return mn_a < mn_b;
    }
    return mx_a < mx_b;

    //return mn_a+mx_a < mn_b + mx_b;
}

void solve()
{
    int n; cin>>n;
    vector<pair<int,int>> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i].first>>A[i].second;
    }
    sort(A.begin(),A.end(),cmp);

    for(auto &ele:A)
    {
        cout << ele.first << " " << ele.second << " ";
    }
    cout << endl;
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