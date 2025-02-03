#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int long long
typedef long long ll;
typedef long double ld;

class DisjointSets {

  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}
	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }
	bool unite(int x, int y) {

		int x_root = find(x);

		int y_root = find(y);

		if (x_root == y_root) { return false; }


		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }

		sizes[x_root] += sizes[y_root];

		parents[y_root] = x_root;

		return true;

	}
	bool connected(int x, int y) { return find(x) == find(y); }

};

void solve()
{
    int n,m1,m2; cin>>n>>m1>>m2;
    vector<int> F[n];
    vector<int> G[n];

    DisjointSets dsu(n);
    DisjointSets dsu2(n);

    for(int i=0;i<m1;i++)
    {
        int u,v; cin>>u>>v; --u;--v;
        dsu.unite(u,v);
    }

    for(int i=0;i<m1;i++)
    {
        int u,v; cin>>u>>v; --u;--v;
        dsu2.unite(u,v);
    }
    int output = 0;
    for(int i=0;i<n;i++)
    {
        int h = dsu.find(i);
        int g = dsu2.find(i);

        if(h!=g)
        {
            output += 2;
        }
    }

    cout << output << endl;

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