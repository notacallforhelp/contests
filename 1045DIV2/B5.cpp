#include <bits/stdc++.h>
using namespace std;

vector<int> primes = {3, 5, 7, 11, 13, 17, 19, 23, 29};

int pow_mod(int base, int exp, int mod) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) 
            res = (res * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &a : A) cin >> a;

    if (k % 2 != 0) {
        for (int i = 0; i < n; i++) {
            if (A[i] % 2 != 0) 
                A[i] += k;
        }
    } else {
        int p = 0;
        for (int prime_val : primes) {
            if (k % prime_val != 0) {
                p = prime_val;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            int r = A[i] % p;
            int k_mod = k % p;
            int inv_k = pow_mod(k_mod, p-2, p);
            int c_i = ((p - r) * inv_k) % p;
            A[i] += k * c_i;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}