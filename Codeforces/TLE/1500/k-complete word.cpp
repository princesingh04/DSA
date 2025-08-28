#include <iostream>
#include <vector>
#include <string>
#include <numeric> // For std::accumulate
#include <algorithm> // For std::max_element

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    int min_changes = 0;

    // We only need to iterate up to the first k/2 positions (or up to k-1 for the pairs)
    // because the palindrome rule mirrors everything.
    // The total number of groups of indices is k.
    // The first k/2 groups are unique, and the groups from k/2 to k-1 are mirrors.
    // So we iterate through the first half of the k-length block.
    for (int i = 0; i < k / 2; ++i) {
        // This vector stores the counts of each character ('a' to 'z') for the current group.
        std::vector<int> char_counts(26, 0);
        int group_size = 0;

        // Find all indices that belong to this group.
        // The first half of the group is determined by the periodicity rule.
        for (int j = i; j < n; j += k) {
            char_counts[s[j] - 'a']++;
            group_size++;
        }

        // The other half of the group is determined by the palindrome rule.
        // It mirrors the first half of the k-length block from the other side of the string.
        for (int j = k - 1 - i; j < n; j += k) {
            char_counts[s[j] - 'a']++;
            group_size++;
        }
        
        // Find the count of the most frequent character in this group.
        int max_freq = *std::max_element(char_counts.begin(), char_counts.end());

        // The number of changes needed for this group is the total size minus the max frequency.
        min_changes += group_size - max_freq;
    }
    
    // Handle the middle element if k is odd.
    // The middle position (k/2) of a k-length block will not have a palindromic partner within the same block.
    if (k % 2 != 0) {
        std::vector<int> char_counts(26, 0);
        int group_size = 0;
        
        // Find all indices that belong to the middle group.
        for (int j = k / 2; j < n; j += k) {
            char_counts[s[j] - 'a']++;
            group_size++;
        }
        
        int max_freq = *std::max_element(char_counts.begin(), char_counts.end());
        min_changes += group_size - max_freq;
    }

    std::cout << min_changes << std::endl;
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
