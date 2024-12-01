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
    vector<pair<int,int>> skillone(3);
    vector<pair<int,int>> skilltwo(3);
    vector<pair<int,int>> skillthree(3);

    for(int i=0;i<3;i++)
    {
        int x,y,z;cin>>x>>y>>z;
        skillone[i]={x,i};
        skilltwo[i]={y,i};
        skillthree[i]={z,i};
    }

    //cout << endl;

    sort(skillone.begin(),skillone.end());
    sort(skilltwo.begin(),skilltwo.end());
    sort(skillthree.begin(),skillthree.end());

    /*for(auto ele:skillone)
    {
        cout << ele.first << " " << ele.second <<endl;
    }

    cout << endl;

    for(auto ele:skilltwo)
    {
        cout << ele.first << " " << ele.second <<endl;
    }

    cout << endl;

    for(auto ele:skillthree)
    {
        cout << ele.first << " " << ele.second <<endl;
    }

    cout << endl;*/

    vector<int> order(3);

    for(int i=0;i<3;i++)
    {
        order[i]=skillone[i].second;
    }

    for(int i=0;i<3;i++)
    {
        if(skilltwo[i].second!=order[i]||skillthree[i].second!=order[i])
        {
            cout << "no" << endl;
            return;
        }
    }

    /*for(auto ele:order)
    {
        cout << ele << " ";
    }
    cout << endl;*/
    
    bool firstpair=false;
    bool secondpair=false;

    for(int i=0;i<2;i++)
    {
        //cout << order[i] << " " << order[i+1] << endl;
        if(skillone[i].first<skillone[i+1].first)
        {
            if(i==0){
                firstpair=true;
            }
            else
            {
                secondpair=true;
            }
        }
        if(skilltwo[i].first<skilltwo[i+1].first)
        {
            if(i==0){
                firstpair=true;
            }
            else
            {
                secondpair=true;
            }
        }
        if(skillthree[i].first<skillthree[i+1].first)
        {
            if(i==0){
                firstpair=true;
            }
            else
            {
                secondpair=true;
            }
        }
    }
    //cout << firstpair << " " << secondpair << endl;
    if(firstpair&&secondpair)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
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
}