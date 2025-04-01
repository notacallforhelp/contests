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
    int n; cin>>n;
    string s; cin>>s;
    if(n==1)
    {
        cout << -1 << endl;
        return;
    }
    map<char,int> M;
    for(auto &ele:s)
    {
        M[ele]++;
    }
    int mxfreq = 0;
    for(auto &ele:M)
    {
        mxfreq = max(mxfreq,ele.second);
    }
    vector<pair<int,int>> pr;
    for(auto &ele:M)
    {
        pr.push_back({ele.second,ele.first});
    }
    sort(pr.begin(),pr.end());
    set<char> inc;
    int stepsneeded = 0;

    for(auto &ele:M)
    {
        if(ele.second<mxfreq)
        {
            inc.insert(ele.first);
        }
        stepsneeded += mxfreq-ele.second;
    }
    if(stepsneeded>2*n)
    {
        cout << -1 << endl;
        return;
    }
    if(inc.size()==0)
    {
        cout << 0 << endl;
        return;
    }
    else if(inc.size()==1)
    {
        char target = *inc.begin();
        int booster = 0;
        int ptr = 0;
        vector<int> ans;
        while(stepsneeded&&ptr+1<n)
        {
            if(s[ptr]!=s[ptr+1]&&s[ptr]!=target&&s[ptr+1]!=target)
            {
                --stepsneeded;
                ans.push_back(ptr+booster);
                ++booster;
            }
            ++ptr;
        }
        if(stepsneeded>0)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            for(auto &ele:ans)
            {
                cout << ele+1 << endl;
            }
        }
    }
    else if(inc.size()==2)
    {
        char smaller = pr[0].second;
        char bigger = pr[1].second;
        int highest = pr[2].first;
        vector<int> ans;
        if(M[smaller]==M[bigger])
        {
            int idx = -1;
            for(int i=0;i+1<n;i++)
            {
                if(s[i]!=s[i+1])
                {
                    idx = i;
                    break;
                }
            }
            if(idx==-1)
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                cout << (highest-M[smaller])*2 << endl;
                for(int i=0;i<(highest-M[smaller])*2;i++)
                {
                    cout << idx+1 << endl;
                    ++idx;
                }
                return;
            }
        }
        bool better = false;
        bool worse = false;
        int betteridx = -1;
        int worseidx = -1;
       
        for(int i=0;i+1<n;i++)
        {
            if(s[i]!=s[i+1]&&s[i]!=smaller&&s[i+1]!=smaller)
            {
                better = true;
                if(betteridx==-1)
                {
                    betteridx = i;
                }
            }
            if(s[i]!=s[i+1]&&s[i]!=bigger&&s[i+1]!=bigger)
            {
                worse = true;
                if(worseidx==-1)
                {
                    worseidx = i;
                }
            }
        }
        if(better)
        {
            int left = (highest-M[smaller]) - (highest-M[bigger])-1;
            int booster = (highest-M[bigger])*2+1;

            for(int i=0;i<booster;i++)
            {
                ans.push_back(betteridx);
                ++betteridx;
            }
            int ptr = 0;
            while(left&&ptr+1<n&&ptr!=betteridx)
            {
                if(s[ptr]!=s[ptr+1]&&s[ptr]!=smaller&&s[ptr+1]!=smaller)
                {
                    --left;
                    ans.push_back(ptr+booster);
                    ++booster;
                }
                ++ptr;
            }
            if(left>0)
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                cout << ans.size() << endl;
                for(auto &ele:ans)
                {
                    cout << ele+1 << endl;
                }
                return;
            }
        }
        else if(worse)
        {
            int left = (highest-M[smaller]) - (highest-M[bigger]);
            int booster = (highest-M[bigger])*2;

            for(int i=0;i<booster;i++)
            {
                ans.push_back(worseidx);
                ++worseidx;
            }
            
            int ptr = 0;

            while(left&&ptr+1<n&&ptr!=worseidx)
            {
                if(s[ptr]!=s[ptr+1]&&s[ptr]!=smaller&&s[ptr+1]!=smaller)
                {
                    --left;
                    ans.push_back(ptr+booster);
                    ++booster;
                }
                ++ptr;
            }

            if(left>0)
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                cout << ans.size() << endl;
                for(auto &ele:ans)
                {
                    cout << ele+1 << endl;
                }
                return;
            }
        }
        else
        {
            cout << -1 << endl;
            return;
        }
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