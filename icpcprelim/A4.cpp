#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef long double ld;

//ordered_sets
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const int N = 2e5 + 10;
int pf[N];

void solve()
{
    int n, m; cin >> n >> m;

    vector<int> A(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    pf[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + A[i];
    }

    vector<int> answer(n + 1,0);

    for(int i=0;i<=n;i++)
    {
        answer[i]=0;
    }

    for (int i = 0; i < m; i++)
    {
        answer[i] = pf[i];
    }

    for (int r = m, l = 0; r <= n; r++, l++)
    {
        int discount = pf[r - 1] - pf[l];
        if ((r - 1) % m == 0)
        {
            discount = pf[r - 1] - pf[l];
            //cout << A[r]<<endl;
            answer[r] = answer[l - 1] + A[r] + discount;
        }
        else
        {
            answer[r] = answer[r - 1] + A[r];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //setIO("problemname");

    int t; cin >> t;

    while (t--)
    {
        solve();
    }
}