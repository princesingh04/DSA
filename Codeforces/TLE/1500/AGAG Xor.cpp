#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int total_xor = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        total_xor ^= a[i];
    }

    // Case 1: The total XOR sum is 0.
    // This means we can always partition the array into two blocks
    // with an equal XOR sum, leading to a final array like [V, V].
    if (total_xor == 0) {
        std::cout << "YES\n";
        return;
    }

    // Case 2: The total XOR sum is X (not 0).
    // We need to see if we can partition the array into at least three
    // blocks that each have an XOR sum of X.
    // We can check this by finding at least two non-overlapping segments
    // that have an XOR sum of X. If we find two, the third is guaranteed.
    int count = 0;
    int current_xor = 0;
    for (int i = 0; i < n; ++i) {
        current_xor ^= a[i];
        if (current_xor == total_xor) {
            count++;
            current_xor = 0; // Reset to find the next segment
        }
    }

    // If we found at least 2 segments and the rest of the array
    // XOR'd to 0 (meaning the last segment was also valid), we can win.
    // This corresponds to a partition like [X, X, X].
    if (count >= 2 && current_xor == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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