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
    string a, b; cin>>a>>b;

    vector<pair<char,int>> A;
    vector<pair<char,int>> B;

    int sza = a.length();
    int szb = b.length();

    for(int i=0;i<sza;i++)
    {
        char v = a[i];
        int curr = 0;

        while(i<sza&&v==a[i])
        {
            ++curr;
            ++i;
        }

        --i;
        A.push_back({v,curr});
    }

    for(int i=0;i<szb;i++)
    {
        char v = b[i];
        int curr = 0;

        while(i<szb&&v==b[i])
        {
            ++curr;
            ++i;
        }

        --i;
        B.push_back({v,curr});
    }

    int Bptr = 0;
    int Aptr = 0;

    int sizeA = A.size(); int sizeB = B.size();

    int cost = 0;
    int costfactor = 1;

    /*for(auto &ele:A)
    {
        cout << ele.first << ", " << ele.second << endl;
    }
    cout << endl;

    for(auto &ele:B)
    {
        cout << ele.first << ", " << ele.second << endl;
    }

    cout << endl;*/

    for(int i=0;i<sizeB;i++)
    {
        int cf = B[i].second;
        while(Aptr<sizeA&&B[i].second!=0)
        {
            if(A[Aptr].first!=B[i].first)
            {
                cost += costfactor*(A[Aptr].second);
            }
            else
            {
                int red = max(A[Aptr].second-B[i].second,0ll);
                B[i].second = max(0ll,B[i].second-A[Aptr].second);
                cost += costfactor*red;
            }
            ++Aptr;
        }
        costfactor += cf;
        ++Bptr;
        /*if(Aptr==sizeA&&i!=sizeB-1)
        {
            cout << -1 << endl;
            return;
        }
        else if(Aptr==sizeA&&i==sizeB-1&&B[i].second!=0)
        {
            cout << -1 << endl;
            return;
        }*/
        if(Aptr==sizeA)
        {
            if(B[i].second!=0)
            {
                cout << -1 << endl;
                return;
            }
        }
        else if(i==sizeB-1&&Aptr!=sizeA)
        {
            while(Aptr!=sizeA)
            {
                cost += A[Aptr].second*costfactor;
                ++Aptr;
            }
        }
    }

    cout << cost << endl;

    /*for(auto &ele:A)
    {
        cout << ele.first << ", " << ele.second << endl;
    }
    cout << endl;

    for(auto &ele:B)
    {
        cout << ele.first << ", " << ele.second << endl;
    }*/
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