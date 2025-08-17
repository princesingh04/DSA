#include <iostream>
#include <vector>
#include <numeric>

// Use long long for potentially large numbers to avoid overflow
using ll = long long;

void solve() {
    int n;
    ll a, b;
    std::cin >> n >> a >> b;

    std::vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    ll total_cost = 0;
    ll capital_pos = 0;

    for (int i = 0; i < n; ++i) {
        // --- Step 1: Conquer (This is mandatory) ---
        // The distance to conquer the current kingdom x[i] from our capital
        ll conquer_dist = x[i] - capital_pos;
        // Add the conquest cost to the total
        total_cost += b * conquer_dist;

        // --- Step 2: Decide whether to move the capital (Greedy Choice) ---
        // This decision is only relevant if there are kingdoms left to conquer
        if (i < n - 1) {
            // The one-time cost to move the capital to the newly conquered kingdom
            ll move_cost = a * conquer_dist;

            // The number of kingdoms remaining after this one
            ll num_remaining_kingdoms = n - 1 - i;
            
            // The total savings we would get on all future conquests.
            // For each remaining kingdom, the conquering distance is shorter by 'conquer_dist'.
            ll future_savings = b * num_remaining_kingdoms * conquer_dist;

            // If the investment (move_cost) is less than the payoff (future_savings),
            // it's optimal to move.
            if (move_cost < future_savings) {
                total_cost += move_cost;
                capital_pos = x[i];
            }
        }
    }

    std::cout << total_cost << '\n';
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}