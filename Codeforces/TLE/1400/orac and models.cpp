#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    // s array is 1-indexed for problem statement clarity
    std::vector<int> s(n + 1); 
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];
    }

    // dp[i] = length of the longest beautiful arrangement ending with model i
    // Base case: every model forms a beautiful arrangement of length 1
    std::vector<int> dp(n + 1, 1); 

    int max_models = 1; // At least one model can be bought

    // Iterate through all models i from 1 to n
    for (int i = 1; i <= n; ++i) {
        // For each model i, iterate through its multiples j = 2i, 3i, 4i, ...
        // These are the only possible successors to model i in a beautiful arrangement
        for (int j = 2 * i; j <= n; j += i) {
            // Check the size rule: s_i < s_j
            if (s[i] < s[j]) {
                // If we can extend a beautiful arrangement ending at i with model j,
                // update dp[j] to be the max of its current value and (dp[i] + 1)
                dp[j] = std::max(dp[j], dp[i] + 1);
            }
        }
        // Keep track of the overall maximum length found so far
        max_models = std::max(max_models, dp[i]);
    }

    std::cout << max_models << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}