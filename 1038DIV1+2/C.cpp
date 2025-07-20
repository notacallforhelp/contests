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

*/

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/

bool cmp(pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b)
{
    int s = a.first.first+a.first.second;
    int s2 = b.first.first+b.first.second;

    if(s!=s2)
    {
        return s < s2;
    }
    else
    {
        return a < b;
    }
}

void solve()
{
    int n; cin>>n;
    vector<pair<pair<int,int>,int>> bothneg;
    vector<pair<pair<int,int>,int>> bothpos;
    vector<pair<pair<int,int>,int>> posneg;
    vector<pair<pair<int,int>,int>> negpos;

    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        if(x<0&&y<0)
        {
            bothneg.push_back({{x,y},i+1});
        }
        else if(x>=0&&y>=0)
        {
            bothpos.push_back({{x,y},i+1});
        }
        else if(x<0&&y>=0)
        {
            negpos.push_back({{x,y},i+1});
        }
        else
        {
            posneg.push_back({{x,y},i+1});
        }
    }

    sort(bothneg.begin(),bothneg.end());
    sort(bothpos.begin(),bothpos.end());
    sort(negpos.begin(),negpos.end());
    sort(posneg.begin(),posneg.end());
    reverse(bothpos.begin(),bothpos.end());
    reverse(posneg.begin(),posneg.end());
    //reverse(negpos.begin(),negpos.end());

    /*cout << endl;

    for(auto &ele:negpos)
    {
        cout << ele.first.first << " " << ele.first.second << endl;
    }

    cout << endl;

    for(auto &ele:posneg)
    {
        cout << ele.first.first << " " << ele.first.second << endl;
    }*/

    vector<pair<pair<int,int>,int>> leftover;

    int s = 0;
    int sz = min(bothneg.size(),bothpos.size());
    int sz2 = min(posneg.size(),negpos.size());

    for(int i=0;i<sz;i++)
    {
        cout << bothneg[i].second << " " << bothpos[i].second << endl;
        s += abs(bothneg[i].first.first-bothpos[i].first.first);
        s += abs(bothneg[i].first.second-bothpos[i].first.second);
    }

    for(int i=0;i<sz2;i++)
    {
        cout << posneg[i].second << " " << negpos[i].second << endl;
        s += abs(posneg[i].first.first-negpos[i].first.first);
        s += abs(posneg[i].first.second-negpos[i].first.second);
    }

    for(int i=sz;i<bothneg.size();i++)
    {
        leftover.push_back(bothneg[i]);
    }
    for(int i=sz;i<bothpos.size();i++)
    {
        leftover.push_back(bothpos[i]);
    }

    for(int i=sz2;i<posneg.size();i++)
    {
        leftover.push_back(posneg[i]);
    }
    for(int i=sz2;i<negpos.size();i++)
    {
        leftover.push_back(negpos[i]);
    }

    sort(leftover.begin(),leftover.end(),cmp);

    int p = leftover.size();

    for(int i=0;i<p/2;i++)
    {
        cout << leftover[i].second << " " << leftover[p-i-1].second << endl;
        s += abs(leftover[i].first.first-leftover[p-i-1].first.first);
        s += abs(leftover[i].first.second-leftover[p-i-1].first.second);
    }

    //cout << s << endl;
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