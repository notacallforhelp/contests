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

void solve()
{
    int n; cin>>n; ll x; cin>>x;

    ll A[n][n];

    ll sum = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
            sum += A[i][j];
        }
    }

    int from = 0;
    int upto = n-1;
    int ct = 0;
    bool flag = false;

    while(x>0&&sum>0)
    {
        for(int i=from;i<=upto;i++)
        {
           if(x-A[from][i]<0||sum==0) 
            {
                flag = true;
                break;
            }
            
            x -= A[from][i];
            sum -= A[from][i];
            ++ct;
        }
        if(flag) break;

        for(int i=from+1;i<=upto;i++)
        {
            if(x-A[i][upto]<0||sum==0) 
            {
                flag = true;
                break;
            }
            
            x -= A[i][upto];
            sum -= A[i][upto];
            ++ct;
        }
        if(flag) break;

        for(int i=upto-1;i>=from;i--)
        {
            if(x-A[upto][i]<0||sum==0)
            {
                flag = true;
                break;
            }
            
            x -= A[upto][i];
            sum -= A[upto][i];
            ++ct;
        }

        if(flag) break;

        for(int i=upto-1;i>from;i--)
        {
            if(x-A[i][from]<0||sum==0)
            {
                flag = true;
                break;
            }
            
            x-= A[i][from];
            sum -= A[i][from];
            ++ct;

        }

        if(flag) break;

        ++from;
        --upto;
    }
    cout << ct << endl;
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