#include <iostream>
#include <string>
#include <vector>
#include <utility> // For std::pair

// Function to solve a single test case
void solve() {
    // Read the inputs for the test case
    std::string s;
    std::cin >> s;
    long long pos;
    std::cin >> pos;
    
    int n = s.length();

    // ====================================================================
    // Part 1: Find k (removals) and final_pos using an iterative loop
    // ====================================================================
    int removals = 0;
    int current_len = n;
    
    while (pos > current_len) {
        pos -= current_len;
        current_len--;
        removals++;
    }
    
    long long final_pos = pos; // The remaining pos is the 1-based index

    // ====================================================================
    // Part 2: Build the final string after 'removals' using a monotonic stack
    // ====================================================================
    std::string result_stack;
    int k = removals;

    for (char c : s) {
        // While the stack is not empty, we still have removals left,
        // AND the last character on the stack is greater than the current one...
        while (!result_stack.empty() && k > 0 && result_stack.back() > c) {
            // ...it's a "peak" that should be removed.
            result_stack.pop_back();
            k--; // Use up one removal
        }
        // Add the current character to the stack.
        result_stack.push_back(c);
    }

    // After the loop, if we still have removals left (k > 0), it means
    // the string became sorted. The optimal strategy is to remove from the end.
    while (k > 0) {
        result_stack.pop_back();
        k--;
    }

    // ====================================================================
    // Part 3: Print the character at the final position
    // ====================================================================
    // We use final_pos - 1 because strings are 0-indexed in C++.
    std::cout << result_stack[final_pos - 1];
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
    // The problem asks for the final output string to be concatenated
    // so we don't print a newline here.
    
    return 0;
}