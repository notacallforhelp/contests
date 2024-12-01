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
    int n; cin>>n;

    vector<int> digits;

    int temp = n;
    while(temp)
    {
        digits.push_back(temp%10);
        temp=temp/10;
    }
    reverse(digits.begin(),digits.end());

    int ptr = 0;

    while(ptr<digits.size()&&digits[ptr]!=0)
    {
        ++ptr;
    }

    if(ptr==digits.size())    //no zero
    {
        int mx = digits[0];
        int mx_idx=0;
        for(int i=0;i<ptr;i++)
        {
            if(digits[i]>mx)
            {
                mx = digits[i];
                mx_idx=i;
            }
        }

        for(int i=0;i<ptr;i++)
        {
            if(i!=mx_idx)
            {
                cout << digits[i];
            }
        }
        cout << endl;
    }
    else
    {
        int mx = digits[0];
        int mx_idx = 0;

        for(int i=0;i<ptr;i++)
        {
            if(digits[i]>mx)
            {
                mx = digits[i];
                mx_idx=i;
            }
        }
        for(int i=0;i<ptr;i++)
        {
            if(i!=mx_idx)
            {
                cout << digits[i];
            }
        }

        if(ptr==1)
        {
             while(ptr<digits.size()&&digits[ptr]==0)
            {
                ++ptr;
            }
        }

        if(ptr==digits.size())
        {
            cout << 0;
        }

        for(int i=ptr;i<digits.size();i++)
        {
            cout << digits[i];
        }
        cout << endl;
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
    return 0;
}