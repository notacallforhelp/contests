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
*/

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/

void solve()
{
    int n; cin>>n;
    vector<int> A(n); for(auto &i:A)cin>>i;

    int output = 0;  //min the answerr will be 0

    deque<int> non_neg;
    deque<int> neg;

    for(int i=0;i<n;i++)
    {
        if(A[i]>=0)
        {
            non_neg.push_back(A[i]);
        }
        else
        {
            neg.push_back(A[i]);
        }
    }

    vector<int> hmm;

    int s = 0;

    /*for(auto &ele:non_neg)
    {
        cout << ele << " ";
    }
    cout << endl;

    for(auto &ele:neg)
    {
        cout << ele << " ";
    }
    cout << endl;*/

    for(int i=0;i<n;i++)
    {
        if(non_neg.empty()||neg.empty())
        {
            break;
        }
        hmm.push_back(non_neg.front());
        s += non_neg.front();
        
        non_neg.pop_front();
        while(!neg.empty()&&s>0)
        {
            hmm.push_back(neg.front());
            s += neg.front();
            //cout << s << endl;
            neg.pop_front();
        }
    }

    while(!non_neg.empty())
    {
        hmm.push_back(non_neg.front());
        non_neg.pop_front();
    }

    while(!neg.empty())
    {
        hmm.push_back(neg.front());
        neg.pop_front();
    }

    int g=hmm[0];
    int l=hmm[0];

    /*for(int i=0;i<n;i++)
    {
        cout << hmm[i] << " ";
    }
    cout << endl;*/

    for(int i=1;i<n;i++)
    {
        l=max(hmm[i],l+hmm[i]);
        g=max(l,g);
    }

    if(g<0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << g << endl;
    }

    //cout << max(g,output) << endl;
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