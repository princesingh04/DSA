#include <iostream>
#include <vector>
#include <numeric>
#include <map>

// Function to calculate nC2 (n choose 2)
// nC2 = n * (n - 1) / 2
long long combinations(long long n) {
    if (n < 2) {
        return 0;
    }
    return n * (n - 1) / 2;
}

void solve() {
    long long a, b, k;
    std::cin >> a >> b >> k;

    // Use vectors to store the frequency of each boy and girl.
    // The sizes are a+1 and b+1 because IDs are 1-indexed up to a and b.
    std::vector<int> boys_count(a + 1, 0);
    std::vector<int> girls_count(b + 1, 0);

    std::vector<int> boys_pairs(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> boys_pairs[i];
        boys_count[boys_pairs[i]]++;
    }

    std::vector<int> girls_pairs(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> girls_pairs[i];
        girls_count[girls_pairs[i]]++;
    }

    // Step 1: Calculate the total number of ways to choose any two pairs.
    // This is k choose 2.
    long long total_combinations = combinations(k);

    // Step 2: Calculate the number of invalid combinations (pairs sharing a boy).
    long long invalid_boys_combinations = 0;
    for (int count : boys_count) {
        invalid_boys_combinations += combinations(count);
    }

    // Step 3: Calculate the number of invalid combinations (pairs sharing a girl).
    long long invalid_girls_combinations = 0;
    for (int count : girls_count) {
        invalid_girls_combinations += combinations(count);
    }

    // Step 4: The total number of valid combinations is the total number of combinations
    // minus the invalid combinations.
    long long valid_combinations = total_combinations - invalid_boys_combinations - invalid_girls_combinations;

    std::cout << valid_combinations << std::endl;
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