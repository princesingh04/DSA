#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Use long long for monster counts and sums to avoid potential overflow.
using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // 1. Sort the hordes to easily access the smallest ones.
    std::sort(a.begin(), a.end());

    // 2. Create a prefix sum array to find the sum of the smallest k hordes.
    std::vector<ll> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    // 3. Calculate the baseline number of single attacks needed.
    // This is ceil(total_monsters / 2).
    ll total_monsters = prefix_sum[n];
    ll tmp = (total_monsters + 1) / 2;

    // 4. Find the "breakpoint" where the sum of small hordes exceeds the baseline.
    // std::upper_bound finds the first prefix sum that is > tmp.
    auto it = std::upper_bound(prefix_sum.begin(), prefix_sum.end(), tmp);
    
    // The index of this breakpoint tells us how many small hordes are "fuel".
    // The remaining hordes are the "big targets".
    int breakpoint_index = std::distance(prefix_sum.begin(), it) - 1;
    
    // 5. The correction factor 'c' is the number of "big target" hordes.
    ll c = n - breakpoint_index;

    // 6. The final answer is the baseline + the correction factor.
    std::cout << tmp + c << "\n";
}

int main() {
    // Fast I/O for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
