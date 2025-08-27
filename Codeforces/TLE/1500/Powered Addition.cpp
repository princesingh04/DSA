#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For std::log2

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n); // Use long long to avoid overflow with large values
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n <= 1) {
        std::cout << 0 << std::endl;
        return;
    }

    long long max_so_far = a[0];
    int max_time = 0;

    for (int i = 1; i < n; ++i) {
        if (a[i] < max_so_far) {
            // 1. Correctly calculate the positive difference
            long long diff = max_so_far - a[i];
            
            // 2. Correctly calculate the time T needed for this difference.
            // T is the number of bits in the binary representation of diff.
            int time_needed = 0;
            if (diff > 0) {
                // Find the highest set bit. For a number d, the bit length is floor(log2(d)) + 1.
                time_needed = static_cast<int>(floor(log2(diff))) + 1;
            }

            // The overall time is the maximum time needed for any single fix.
            max_time = std::max(max_time, time_needed);
            
            // Conceptually, a[i] is now raised to max_so_far, but we don't
            // need to actually change it in the array. We just need to know
            // that the non-decreasing property holds up to this point.

        } else {
            // 3. Correctly update max_so_far only when we find a larger element.
            max_so_far = a[i];
        }
    }

    std::cout << max_time << std::endl;
}

// You can keep your main function as it is.
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t = 1;
    std::cin >> t;
    while(t--) solve();
    return 0;
}