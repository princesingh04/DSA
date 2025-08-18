#include <iostream>
#include <vector>
#include <map>

// Use a shorter alias for long long for convenience
using ll = long long;

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Use a map to store the frequency of each interest value.
    // Key: interest value (-10 to 10), Value: number of clients.
    std::map<int, ll> counts;
    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        counts[t]++;
    }

    ll total_pairs = 0;

    // --- Step 1: Handle non-zero opposites (x vs -x) ---
    // We loop through the positive values (1 to 10) to avoid double-counting.
    for (int i = 1; i <= 10; ++i) {
        // If a key doesn't exist, map[key] will return 0, which is perfect for the multiplication.
        total_pairs += counts[i] * counts[-i];
    }

    // --- Step 2: Handle the zero case (0 vs 0) ---
    // We need to choose 2 clients from the group of clients with t=0.
    // The formula for "k choose 2" is k * (k - 1) / 2.
    ll count_zero = counts[0];
    total_pairs += count_zero * (count_zero - 1) / 2;

    std::cout << total_pairs << std::endl;

    return 0;
}