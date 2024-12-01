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

void solve()
{
    int n, k; cin>>n>>k;

    vector<ll> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    map<int,int> M;

    for(int i=0;i<n;i++)
    {
        ++M[A[i]];
    }

    vector<pair<int,int>> V;
    for(auto &y:M)
    {
        V.push_back(y);
    }

    int l=0;
    int sum=0;
    int ans = 0;
    for(int r=0;r<V.size();r++)
    {
        sum += V[r].second;

        if(r!=0&&(V[r].first-V[r-1].first>1))
        {
            sum = V[r].second;
            l=r;
        }
        if(r-l+1>k)
        {
            sum -= V[l].second;
            ++l;
        }
        ans = max(ans,sum);
    }
    cout << ans << endl;
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