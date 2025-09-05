#include <iostream>
#include <string>
#include <vector>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    long long ans = 0;
    long long count_before_b = 0;
    long long MOD = 1e9 + 7;

    for (char c : s) {
        if (c == 'a') {
            // This 'a' can start a new sequence (1) or extend any
            // of the 'count_before_b' sequences.
            long long new_sequences = (1 + count_before_b) % MOD;
            
            // Add the new sequences ending at this 'a' to the total answer.
            ans = (ans + new_sequences) % MOD;
        } else if (c == 'b') {
            // This 'b' acts as a checkpoint. All sequences found so far
            // are now validated and can be extended by future 'a's.
            // We update our "prefix sum" here.
            count_before_b = ans;
        }
        // For any other character, we do nothing.
    }

    std::cout << ans << std::endl;

    return 0;
}