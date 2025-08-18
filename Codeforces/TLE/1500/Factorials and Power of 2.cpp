#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Use a shorter alias for long long
using ll = long long;

// A global vector to store the pre-computed factorials (3! to 14!)
std::vector<ll> factorials;

// This function calculates the factorials we need just once
void precompute_factorials() {
    ll current_fact = 1;
    // We only care about factorials from 3! onwards
    for (int i = 1; i <= 15; ++i) {
        // Prevent overflow, although 15! is the first to exceed 10^12
        if (__builtin_mul_overflow(current_fact, i, &current_fact)) {
            break;
        }
        if (i >= 3) {
            // Stop if the factorial is larger than our max N
            if (current_fact > 1000000000000LL) {
                break;
            }
            factorials.push_back(current_fact);
        }
    }
}

void solve() {
    ll n;
    std::cin >> n;

    // 1. Establish the baseline answer using only powers of two.
    // The popcount of n gives the number of terms in its binary representation.
    int min_k = __builtin_popcountll(n);

    int num_special_factorials = factorials.size(); // This will be 12

    // 2. Iterate through all 2^12 = 4096 subsets of the special factorials
    for (int i = 0; i < (1 << num_special_factorials); ++i) {
        ll factorial_sum = 0;
        int num_factorials_used = 0;

        for (int j = 0; j < num_special_factorials; ++j) {
            // Check if the j-th bit is set in the mask 'i'.
            // This means we include the j-th factorial in our current subset.
            if ((i >> j) & 1) {
                factorial_sum += factorials[j];
                num_factorials_used++;
            }
        }

        // 3. If the sum is valid, calculate the total terms and update the minimum
        if (factorial_sum <= n) {
            ll remainder = n - factorial_sum;
            
            // The total number of terms for this combination is the number of
            // factorials we used plus the number of powers of two (popcount)
            // needed for the remainder.
            int current_k = num_factorials_used + __builtin_popcountll(remainder);
            
            min_k = std::min(min_k, current_k);
        }
    }

    std::cout << min_k << '\n';
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute_factorials();

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}