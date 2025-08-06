#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Fast I/O for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    long long m; // 'm' can be large, but isn't used in the final logic
    std::cin >> n >> m >> k;

    std::vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    // Edge Case: If you have enough or more tape pieces than broken segments,
    // you can cover each broken segment with its own 1cm piece of tape.
    if (k >= n) {
        std::cout << n << std::endl;
        return 0;
    }

    // --- Your Algorithm Starts Here ---

    // 1. Find the Gaps (the cost of all possible "bridges")
    // There are n-1 gaps between n segments.
    std::vector<long long> gaps;
    for (int i = 0; i < n - 1; ++i) {
        // The gap is the space between two consecutive broken segments.
        gaps.push_back(b[i + 1] - b[i] - 1);
    }

    // 2. Sort the Gaps to find the cheapest ones
    std::sort(gaps.begin(), gaps.end());

    // 3. Find how many bridges you must build
    // To connect 'n' islands into 'k' groups, you need to build 'n - k' bridges.
    int bridges_to_build = n - k;

    // 4. Calculate the total length
    // Start with the length needed to cover the 'n' islands themselves.
    long long min_total_length = n;

    // 5. Add the cost of the cheapest bridges
    for (int i = 0; i < bridges_to_build; ++i) {
        min_total_length += gaps[i];
    }

    std::cout << min_total_length << std::endl;

    return 0;
}