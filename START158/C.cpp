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

bool cmp(pair <int,int> &a,pair<int,int> &b)
{
    return abs(a.first-a.second)>abs(b.first-b.second);
    if(abs(a.first-a.second)>abs(b.first-b.second))
    {
        
    }
}

void solve()
{
    int n; cin>>n;
    vector<int> normal(n); for(auto &i:normal)cin>>i;
    vector<int> prom(n); for(auto &i:prom)cin>>i;

    vector<pair<int,int>> hmm(n);

    for(int i=0;i<n;i++)
    {
        hmm[i].first = prom[i];
        hmm[i].second = normal[i];
    }
    sort(hmm.begin(),hmm.end(),cmp);

    /*for(auto ele:hmm)
    {
        cout << ele.first << " " << ele.second << endl;
    }*/
   ll output = 0;
   ll counter = 0;
   ll promcounter=0;
   for(int i=0;i<n;i++)
   {
        if(counter==n-1)
        {
            output += hmm[i].first;
            break;
        }
        else if(promcounter==n-1&&n==2)
        {
            output += hmm[i].second;
            break;
        }
        if(hmm[i].second<=hmm[i].first)
        {
            output += hmm[i].second;
            ++promcounter;
        }
        else
        {
            output += hmm[i].first;
            ++counter;
        }
   }
   cout << output << endl;
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