#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int long long
typedef long long ll;
typedef long double ld;

//ordered_sets
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//struct for range 
struct range
{
    int l,r,index;
    bool operator < (const range &other) const
    {
        if(l==other.l)
            return r>other.r;
        return l < other.l;
    }
};

void solve()
{
    int n,k; cin>>n>>k;
    vector<int> A(n); for(auto &i:A)cin>>i;
    vector<int> B(n); for(auto &i:B)cin>>i;

    vector<pair<int,int>> prs;

    for(int i=0;i<n;i++)
    {
        prs.push_back({min(abs(A[i]-B[i]),9-abs(A[i]-B[i])),max(abs(A[i]-B[i]),9-abs(A[i]-B[i]))});
    }

    sort(prs.begin(),prs.end());

    int sum1 = 0;
    int sum2 = 0;

    for(auto &ele:prs)
    {
        sum1 += ele.first;
    }

    sum2 = 1e18;

    for(auto &ele:prs)
    {
        int j = sum1-ele.first+ele.second;
        if((sum1%2)!=(j%2))
        {
            sum2 = min(sum2,j);
        }
    }

    if(sum1>k)
    {
        cout << "No" << endl;
        return;
    }

    if(sum1<=k)
    {
        int diff = k-sum1;
        if(diff%2==0)
        {
            cout << "Yes" << endl;
            return;
        }
    }

    if(sum2<=k)
    {
        int diff = k-sum2;
        if(diff%2==0)
        {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
    return;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //setIO("problemname");

    int t; cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}