#include <iostream>
#include <vector>
#include <algorithm>

// Define a large number to represent infinity
const int INF = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    // --- Step 1: Gather Positions ---
    // Create a vector of vectors to store indices for each number.
    std::vector<std::vector<int>> positions(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        positions[a[i]].push_back(i);
    }

    // --- Step 2: Find the Largest Gap for Each Number ---
    // min_val_for_k[k] will store the minimum number whose largest gap is k.
    std::vector<int> min_val_for_k(n + 1, INF);

    for (int val = 1; val <= n; ++val) {
        if (!positions[val].empty()) {
            int max_gap = 0;
            int last_pos = -1;

            // Calculate gap between start and first occurrence
            max_gap = std::max(max_gap, positions[val][0] - last_pos);
            last_pos = positions[val][0];

            // Calculate gaps between consecutive occurrences
            for (size_t i = 1; i < positions[val].size(); ++i) {
                max_gap = std::max(max_gap, positions[val][i] - last_pos);
                last_pos = positions[val][i];
            }
            
            // Calculate gap between last occurrence and end
            max_gap = std::max(max_gap, n - last_pos);

            // Now we know 'val' is a candidate for k >= max_gap.
            // We place it at the first k it qualifies for.
            if (max_gap <= n) {
                min_val_for_k[max_gap] = std::min(min_val_for_k[max_gap], val);
            }
        }
    }

    // --- Step 3: Build the Final Answer ---
    // The answer for k is the minimum of all candidates for k' <= k.
    // We can find this by taking a running minimum.
    int current_min = INF;
    for (int k = 1; k <= n; ++k) {
        current_min = std::min(current_min, min_val_for_k[k]);
        
        if (current_min == INF) {
            std::cout << -1 << " ";
        } else {
            std::cout << current_min << " ";
        }
    }
    std::cout << std::endl;
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