#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld __float128
#define ii pair<int, int>
#define pll pair<ll, ll>
#define iii array<int, 3>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LSOne(S) ((S) & -(S))
#define ostree tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}

void solve() {}

void main2() {
    int tc = 1;
    cin >> tc;
    // generate all prime numbers less than n using seive,
    // now, for each prime number less than n,
    for (int i = 0; i < tc; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}

int main() {
    // freopen("four_in_a_burrow_input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    run_with_stack_size(main2, 1024 * 1024 * 1024);
    return 0;
}