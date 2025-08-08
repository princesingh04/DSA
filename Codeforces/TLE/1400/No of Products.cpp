#include <iostream>

int main() {
    // Critical Thing #2: Fast I/O for large inputs.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Critical Thing #1: Use `long long` for total counts to prevent overflow.
    long long total_positive_count = 0;
    long long total_negative_count = 0;

    // DP state variables: counts of subsegments ending at the *previous* position.
    long long ending_pos = 0;
    long long ending_neg = 0;

    // Loop through the array from left to right.
    for (int i = 0; i < n; ++i) {
        int current_num;
        std::cin >> current_num;

        if (current_num > 0) {
            // Case A: Current number is positive (doesn't flip the sign).
            // A new positive subsegment is formed (the number itself).
            ending_pos = ending_pos + 1;
            // The number of negative subsegments ending here is unchanged.
            // ending_neg = ending_neg; (this line is redundant)
        } else { // current_num < 0
            // Case B: Current number is negative (flips the sign).
            // We need temporary storage because we're swapping values.
            long long temp_pos = ending_pos;
            
            // All previous negative subsegments become positive.
            ending_pos = ending_neg;
            // All previous positive subsegments become negative, plus the new one (the number itself).
            ending_neg = temp_pos + 1;
        }

        // Add the counts for subsegments ending at the current position to our grand totals.
        total_positive_count += ending_pos;
        total_negative_count += ending_neg;
    }

    // Print the final answers.
    std::cout << total_negative_count << " " << total_positive_count << std::endl;

    return 0;
}