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

    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    sort(A.begin(),A.end());

    if(k==1)
    {
        ll output = A[n-1]*2;

        output += A[n-2]+A[0];

        cout << output << endl;
        return;
    }

    multiset<int> B;
    B.insert(A[n-1]);

    //cout << *B.begin() << endl;

    int ptr = 0;

    //cout << A[0] << endl;

    while(n-B.size()>k)
    {
        B.insert(A[ptr]);
        ++ptr;
    }
    //cout << endl;
    multiset <int> C;

    while(ptr!=n-1)
    {
        C.insert(A[ptr]);
        ++ptr;
    }

    /*for(auto ele:B)
    {
        cout << ele << " ";
    }
    cout << endl;

    for(auto ele:C)
    {
        cout << ele << " ";
    }
    cout << endl;*/

    ll output = *B.begin() + *B.rbegin() + *C.begin() + *C.rbegin();

    cout << output << endl; 
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}