#include <iostream>
#include <string>
#include <set>
#include <vector>

// Function to solve a single test case to keep the main function clean
void solve() {
    std::string s;
    std::cin >> s;

    // A set to keep track of the characters we've seen
    // since the last pair was successfully formed.
    std::set<char> unpaired_chars;
    
    int kept_count = 0;

    for (char c : s) {
        // Check if the current character is already in our set of unpaired ones.
        // .count() is an efficient way to check for existence in a set.
        if (unpaired_chars.count(c)) {
            // If yes, we've found a pair!
            // We add 2 to the count of characters we're keeping.
            kept_count += 2;
            
            // We clear the set completely because a pair has been finalized.
            // All characters "in between" are discarded, and we start fresh.
            unpaired_chars.clear();
        } else {
            // If no, this is the first time we've seen this character.
            // Add it to our set of unpaired characters, waiting for its match.
            unpaired_chars.insert(c);
        }
    }

    // The minimum number to remove is the total length minus the number we kept.
    int chars_to_remove = s.length() - kept_count;
    std::cout << chars_to_remove << std::endl;
}

int main() {
    // Standard boilerplate for faster input/output in competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }

    return 0;
}