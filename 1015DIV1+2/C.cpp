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
    // return fact[n]*%mod*ifact[n-k]%mod*ifact[k]%mod;
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

void solve()
{
    int n; cin>>n;
    vector<int> A(n+1); //for(auto &i:A)cin>>i;
    vector<int> B(n+1); //for(auto &i:B)cin>>i;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>B[i];
    }
    map<int,int> M1,M2;
    for(int i=1;i<=n;i++)
    {
        M1[A[i]]=B[i];
        M2[B[i]]=A[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(M1[i]!=M2[i])
        {
            cout << -1 << endl;
            return;
        }
    }
    int ct = 0; int idx = -1;
    for(int i=1;i<=n;i++)
    {
        if(A[i]==B[i])
        {
            ++ct;
            idx = i;
        }
    }
    if(n%2==0)
    {
        if(ct>0)
        {
            cout << -1 << endl; return;
        }
    }
    else
    {
        if(ct>1)
        {
            cout << -1 << endl; return;
        }
    }
    vector<int> pos(n+1,-1);//map<int,int> M;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        pos[A[i]]=i;
        //M[B[i]]=A[i];
    }
    vector<pair<int,int>> output;
    if(n%2!=0&&ct==1)
    {
        int mid = n/2+1; //int tmp = A[idx];
        vis[A[idx]]=1;
        if(mid!=idx)
        {
            pos[A[mid]]=idx;
            pos[A[idx]]=mid; 
            output.push_back({idx,mid}); 
            swap(A[mid],A[idx]);
            swap(B[mid],B[idx]); 
        }
    }

    /*for(int i=1;i<=n;i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    for(int i=1;i<=n;i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;

    for(int i=1;i<=n;i++)
    {
        cout << pos[A[i]] << " ";
    }
    cout << endl;*/

    for(int i=1;i<=n;i++)
    {
        if(!vis[A[i]])
        {
            vis[B[i]]=1;
        }
        else
        {
            vis[A[i]]=1;
            int req = n-pos[B[i]]+1;
            int currpos = pos[A[i]];
            if(req!=currpos)
            {
                output.push_back({req,currpos});
                pos[A[req]]=currpos;
                pos[A[currpos]]=req;
                swap(A[req],A[currpos]);
                swap(B[req],B[currpos]);
                i--; 
            }
        }
    }
    vector<int> C(n);
    vector<int> D(n);
    for(int i=1;i<=n;i++)
    {
        C[i-1]=A[i];
    }
    for(int i=1;i<=n;i++)
    {
        D[i-1]=B[n-i+1];
    }
    if(C!=D)
    {
        cout << -1 << endl;
        return;
    }
    cout << output.size() << endl;
    for(auto &ele:output)
    {
        cout << ele.first << " " << ele.second << endl;
    }

    
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