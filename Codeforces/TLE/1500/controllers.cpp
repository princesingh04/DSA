#include <iostream>
#include <string>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int p_count = 0;
    int m_count = 0;
    for (char c : s) {
        if (c == '+') {
            p_count++;
        } else {
            m_count++;
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        long long a, b;
        std::cin >> a >> b;

        // Case 1: The buttons are the same.
        // A score of 0 is only possible if the number of adds and subtracts are equal.
        if (a == b) {
            if (p_count == m_count) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
            continue;
        }

        // Case 2: The buttons are different.
        // We derived the equation: C * (a - b) = (m_count - p_count) * b
        // where C = k - j. We need to find if an integer C exists in the valid range.
        
        long long numerator = (long long)(m_count - p_count) * b;
        long long denominator = a - b;

        // Condition 1: C must be an integer.
        // This means the numerator must be perfectly divisible by the denominator.
        if (numerator % denominator != 0) {
            std::cout << "NO\n";
            continue;
        }

        long long C = numerator / denominator;

        // Condition 2: C must be in the achievable range.
        // The value of C = k - j is constrained by the number of plus/minus rounds.
        // Min C = 0 - m_count = -m_count
        // Max C = p_count - 0 = p_count
        if (C >= -m_count && C <= p_count) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}