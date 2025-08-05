#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Use long long for sums to prevent integer overflow
using ll = long long;

void solve() {
    int n;
    std::cin >> n;

    // We can use a vector of vectors as university IDs are 1 to n.
    // This is slightly more efficient than a map/unordered_map for this problem.
    std::vector<std::vector<ll>> universities(n);
    std::vector<int> u(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> u[i];
    }
    for (int i = 0; i < n; ++i) {
        ll s;
        std::cin >> s;
        // Group skills by university. Adjust for 0-based indexing.
        universities[u[i] - 1].push_back(s);
    }

    // --- Pre-computation Phase ---
    // For each university, sort skills in descending order and calculate prefix sums.
    for (int i = 0; i < n; ++i) {
        if (!universities[i].empty()) {
            // Sort skills from strongest to weakest
            std::sort(universities[i].rbegin(), universities[i].rend());

            // Convert the skills vector into a prefix sum vector in-place
            for (size_t j = 1; j < universities[i].size(); ++j) {
                universities[i][j] += universities[i][j - 1];
            }
        }
    }

    // --- Contribution Phase ---
    // This vector will store the final answer for each k.
    std::vector<ll> final_strengths(n + 1, 0);

    // Iterate through each university and add its contributions.
    for (int i = 0; i < n; ++i) {
        if (universities[i].empty()) {
            continue;
        }

        int m = universities[i].size();
        const auto& prefix_sums = universities[i];

        // For this university, calculate its contribution for every possible team size k
        for (int k = 1; k <= m; ++k) {
            // Number of students that can form full teams
            int count = m - (m % k);
            
            // Add this university's strength to the total for team size k
            // The sum of the top 'count' students is at index 'count - 1'
            final_strengths[k] += prefix_sums[count - 1];
        }
    }

    // --- Output Phase ---
    for (int k = 1; k <= n; ++k) {
        std::cout << final_strengths[k] << (k == n ? "" : " ");
    }
    std::cout << "\n";
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