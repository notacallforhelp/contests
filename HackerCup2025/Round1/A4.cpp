#include "bits/stdc++.h"
using namespace std;
 
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
 
typedef long long ll;
#define vi vector<ll>
#define pb push_back
 
#define nl "\n"
#define print(a)          \
    for (auto &i : a)     \
        cout << i << " "; \
    cout << nl
#define yesno(x) cout << (((x)) ? "YES" : "NO") << nl
#define cntdig(x) floor(log(x) + 1)
 
#define fra(i, init, n, inc) for (i = init; i < n; i += inc)
#define frd(i, init, n, dec) for (i = init; i >= n; i -= dec)
 
bool sortbysec(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
 
void tv(vi &a, ll n)
{
    ll i = 0;
    fra(i, 0, n, 1)
    {
        ll t;
        cin >> t;
        a.pb(t);
    }
}
 
class segment_tree
{
    vector<ll> sg;
    ll n;
 
public:
    segment_tree(ll dn)
    {
        n = dn;
        sg.resize(4 * n);
    }
 
    void build(vector<ll> a, ll start, ll end, ll cur_node)
    {
        if (start == end)
        {
            sg[cur_node] = a[start];
            return;
        }
        ll mid = (start + end) / 2;
        build(a, start, mid, 2 * cur_node);
        build(a, mid + 1, end, 2 * cur_node + 1);
        sg[cur_node] = min(sg[2 * cur_node], sg[2 * cur_node + 1]);
    }
 
    ll query(ll start, ll end, ll cur_node, ll left, ll right)
    {
        if (end < left || start > right)
            return LONG_MAX;
 
        if (start >= left && end <= right)
            return sg[cur_node];
 
        ll mid = (start + end) / 2;
        ll lres = query(start, mid, 2 * cur_node, left, right);
        ll rres = query(mid + 1, end, 2 * cur_node + 1, left, right);
        return min(lres, rres);
    }
};
 
void my_sol()
{
    ll n, q;
    cin >> n >> q;
    vi a;
    tv(a, n);
    segment_tree s(n);
    s.build(a, 0, n - 1, 1);
    vi ans;
    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        ans.push_back(s.query(0, n - 1, 1, l - 1, r - 1));
    }
    for (auto i : ans)
        cout << i << endl;
}
 
int main()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif
 
    // ll t;
    // cin >> t;
    // while (t--)
    my_sol();
 
#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    long double t1 = (long double)duration.count() / 1000000;
    cout << "\n\nTime taken " << fixed << setprecision(6) << t1 << " seconds ";
#endif
    return 0;
}