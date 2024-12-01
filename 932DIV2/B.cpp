/* Includes */
#include <bits/stdc++.h>
 
/* Using libraries */
using namespace std;

/* Defines */
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
 
void solve () {
    int n;
    cin >> n;
    vc <int> a(n);
    vc <int> cntL(n + 1), cntR(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cntR[a[i]]++;
    }
    int mexL = 0, mexR = 0;
    while (cntR[mexR] > 0)
        mexR++;
    for (int i = 0; i < n; ++i) {
        cntL[a[i]]++;
        cntR[a[i]]--;
        if (cntR[a[i]] == 0 && mexR > a[i]) {
            mexR = a[i];
        }
        while (cntL[mexL] > 0)
            mexL++;
        if (mexL == mexR) {
            cout << "2\n";
            cout << 1 << " " << i + 1 << "\n";
            cout << i + 2 << " " << n << "\n";
            return;
        }
    }
    cout << "-1\n";
}

signed main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}