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

const int hjk = 1e7+10;
vector<bool> isprime(hjk,true);

int query[hjk];

void solve(int caseno)
{
    int n;cin>>n;
    cout << "Case #"<<caseno<<": "<<query[n]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //freopen("prime_subtractorization_input.txt","r",stdin);
    //freopen("prime_output_real.txt","w",stdout);

    isprime[0]=isprime[1]=false;

    for(int i=2;i<=hjk;i++)
    {
        for(int j=2*i;j<=hjk;j=j+i)
        {
            isprime[j]=false;
        }
    }
    query[0]=query[1]=query[2]=query[3]=query[4]=0;
    query[5]=2;

    for(int i=6;i<=10000000;i++)
    {
        query[i] += query[i-1];
        if(isprime[i]&&isprime[i-2])
        {
            ++query[i];
        }
    }


    int t; cin>>t;
    int caseno=1;

    while(t--)
    {
        solve(caseno);
        ++caseno;
    }
}