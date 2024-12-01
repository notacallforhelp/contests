#include <bits/stdc++.h>

using namespace std;

int A[100];

int solveGame(int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base cases: when the subarray has only one element
    for (int i = 0; i < n; ++i) {
        dp[i][i] = A[i];
    }

    // Fill the dp table
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = max(A[i] - dp[i + 1][j], A[j] - dp[i][j - 1]);
        }
    }

    // If the score difference is non-negative, George wins or ties
    return dp[0][n - 1] >= 0 ? 0 : 1;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cout << solveGame(n) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}