#include <iostream>
#include <vector>
#include <numeric>

// Helper function to calculate the frequencies of all 1-segment lengths
void calculate_segment_counts(int n, const std::vector<int>& arr, std::vector<long long>& counts) {
    int current_block_length = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 1) {
            current_block_length++;
        } else {
            if (current_block_length > 0) {
                // A block of length L adds (L - s + 1) to the count of segments of length s
                for (int s = 1; s <= current_block_length; ++s) {
                    counts[s] += (long long)(current_block_length - s + 1);
                }
            }
            current_block_length = 0;
        }
    }
    // Handle a block that ends at the very end of the array
    if (current_block_length > 0) {
        for (int s = 1; s <= current_block_length; ++s) {
            counts[s] += (long long)(current_block_length - s + 1);
        }
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    // Step 1: Pre-calculate the counts of 1-segments for each possible length in a and b
    std::vector<long long> counts_a(n + 1, 0);
    std::vector<long long> counts_b(m + 1, 0);

    calculate_segment_counts(n, a, counts_a);
    calculate_segment_counts(m, b, counts_b);

    // Step 2: Iterate through divisors of k to find matching pairs
    long long total_rectangles = 0;
    for (int h = 1; h <= n; ++h) {
        if (k % h == 0) {
            int w = k / h;
            if (w <= m) {
                total_rectangles += counts_a[h] * counts_b[w];
            }
        }
    }

    std::cout << total_rectangles << std::endl;

    return 0;
}