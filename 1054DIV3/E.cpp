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
    // return fact[n]%mod*ifact[n-k]%mod*ifact[k]%mod;
}

ifact[N-1] = pw(fact[N-1],mod-2);
for(int i=N-2;i>=0;i--)
{
    ifact[i]=1ll*ifact[i+1]*(i+1)%mod;
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

BFS

for (int i = 0; i < n; i++) {
		// iterate over all connected components in the graph
		if (!visited[i]) {
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int current_node = q.front();
				q.pop();
				for (int neighbor : adj[current_node]) {
					if (!visited[neighbor]) {
						visited[neighbor] = true;
						q.push(neighbor);
					}
				}
			}
		}
	}

SIEVE

void sieve(int n,vector<bool> &prime)
{
    for(int i=2;i<=n;i++)
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


DSU

const int N = 2e5+10;
int parent[N];int size[N];

void make(int v)
{
    parent[v]=v;
    size[v]=1;
}

int find(int v)
{
    if(v==parent[v]) return v;
    //path compression
    return parent[v] = find(parent[v]);
}

void Union(int a,int b)
{
    a = find(a); b = find(b);
    if(a!=b)
    {
        //union by size
        if(size[a]<size[b]) swap(a,b); 
        parent[b]=a;
        size[a] += size[b];
    }
}

DJIKSTRA

vector<bool> vis(n);
set<pair<int,int>> s;  // {dist,node}
s.insert({0,src})
vector<int> dist(n,INF); dist[src]=0;

while(!s.empty())
{
    auto it = s.begin();
    int v = it->second;
    int d = it->first;
    s.erase(it);

    if(vis[v]) continue;
    vis[v]=1;

    for(auto [child,wt]:adj[v])
    {
        if(!vis[child[ && dist[v]+wt<dist[child])
        {
            //optional
            auto old = s.find({dist[child],child});
            if(old!=s.end()) s.erase(old);

            dist[child]=dist[v]+wt;
            s.insert({dist[child],child});
        }
    }
}

too many modulos then use this

void add_self(int &a,int b)
{
    a += b;
    if(a>=mod) a-=mod;
}

void self_min(int &a,int b)
{
    a = min(a,b);
}

void self_max(int &a,int b)
{
    a = max(a,b);
}

example of iterative dfs
auto dfs = [&](auto&& self, TreeNode* node) -> int {
    if (!node) return 0;
    return 1 + max(self(self, node->left), self(self, node->right));
};
return dfs(dfs, root);

__builtin_clz(a); //returns count of leading zeroes of a, doing 31- that gives first set bit of a 

*/

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/

const int N = 2e5+10;

int n,k,l,r;
int a[N];
vector<int> unic;
int cntx[N];
int cnty[N];

void solve()
{
    cin >> n >> k >> l >> r;
    unic.clear();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        unic.push_back(a[i]);
    }

    sort(unic.begin(),unic.end());
    unic.resize(unique(unic.begin(),unic.end())-unic.begin());

    /*for(int i=0;i<unic.size();i++){
        cout << i<<" " << unic[i] << endl;
    }*/
    
    for(int i=1;i<=n;i++){
        a[i] = lower_bound(unic.begin(),unic.end(),a[i])-unic.begin();
        cntx[i-1]=0;
        cnty[i-1]=0;

        //cout << a[i] << " ";
    }
    //cout << endl;

    int resx = 0;
    int resy = 0;
    ll ans = 0;

    for(int i=1,x=0,y=1;i<=n;i++)
    {
        while(y<=n&&resy<=k)
        {
            if(cnty[a[y]]==0)
            {
                if(resy==k) break;
                resy++;
            }
            cnty[a[y]]++;
            y++;
        }

        while(x+1<=n&&resx<k){
            if(cntx[a[x+1]]==0){
                resx++;
            }
            cntx[a[x+1]]++;
            x++;
        }

        if(resx==k){
            ans += max(min(y-1,i+r-1)-max(x,i+l-1)+1,0ll);
        }
        cntx[a[i]]--;
        cnty[a[i]]--;

        if(cntx[a[i]]==0) --resx;
        if(cnty[a[i]]==0) --resy;
    }

    cout << ans << endl;
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