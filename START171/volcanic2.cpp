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

/*
FOR SIMULATING ALL CELLS THAT SHARE A WALL WITH CURRENT CELL, GRID IS OF SIZE N*M

int dx[]={-1,0,+1,0};
int dy[]={0,-1,0,+1};

inline bool in(int i,int j){
    return (0<=i&&i<n&&0<=j&&j<m);
}


binary exp 

ll binpow(ll a,ll b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2)
    {
        return (a*binpow(a,b-1))%mod;
    }
    return binpow((a*a)%mod,b/2);
}

ceil 

ll ceil2(ll a, ll b) {
    if (a == 0) return 0;
    return (a - 1)/b + 1;
}

COMBINATORICS TEMPLATE 

const int N = 2e5 + 5, mod = 1e9 + 7;
int64_t fact[N];
int64_t pw(int64_t a, int64_t b) {
	int64_t r = 1;
	while(b > 0) {
		if(b & 1) r = (r * a) % mod;
		b /= 2;
		a = (a * a) % mod; 
	}
	return r;
}
int64_t C(int64_t n, int64_t k) {
	if(n < k) return 0LL;
	return (fact[n] * pw((fact[n - k] * fact[k]) % mod, mod - 2)) % mod;
}

void find_divisors()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
}

DFS

vector<vector<int>> adj(n);
vector<bool> visited(n);

void dfs(int current_node) {
	if (visited[current_node]) { return; }
	visited[current_node] = true;

	for (int neighbor : adj[current_node]) { dfs(neighbor); }
}

SIEVE

void sieve(int n,vector<bool> &prime)
{
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i]==true)
        {
            for(int p=i*i;p<=n;p+=i)
            {
                prime[p]=false;
            }
        }
    }
}
prime[0]=prime[1]=false;

*/

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/

ll ceil2(ll a, ll b) {
    if (a == 0) return 0;
    return (a - 1)/b + 1;
}

void solve()
{
    int n,p;
    cin>>n>>p;
    vector<int> A(n); for(auto &i:A)cin>>i;

    vector<int> pos1;
    vector<int> pos2;

    for(int i=1;i<n;i++)
    {
        if(A[i]!=0&&A[i-1]==0)
        {
            pos1.push_back(i);
        }
    }

    for(int i=n-2;i>=0;i--)
    {
        if(A[i]!=0&&A[i+1]==0)
        {
            pos2.push_back(i);
        }
    }

    vector<int> output(n);
    vector<int> output2(n);

    for(auto &ele:pos1)
    {
        int idx = ele;
        output[idx]=ceil2(A[idx],p);
        int val = output[idx];
        ++idx;
        while(idx<n&&A[idx]!=0)
        {
            output[idx] = max(val,ceil2(A[idx],p));
            val = max(val,ceil2(A[idx],p));
            ++idx;
        }
    }

    for(auto &ele:pos2)
    {
        int idx=ele;
        output2[idx]=ceil2(A[idx],p);
        int val = output2[idx];
        --idx;
        while(idx>=0&&A[idx]!=0)
        {
            output2[idx]=max(val,ceil2(A[idx],p));
            val = max(val,ceil2(A[idx],p));
            --idx;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(A[i]==0)
        {
            output[i]=0;
            continue;
        }

        if(output[i]==0)
        {
            output[i]=output2[i];
        }
        else if(output[i]!=0&&output2[i]!=0)
        {
            output[i]=min(output[i],output2[i]);
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
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