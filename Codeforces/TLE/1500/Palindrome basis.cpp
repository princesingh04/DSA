#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAXN = 40001;
const int MOD = 1e9 + 7;

vector<int> palindromes;
vector<ll> dp(MAXN, 0);

// Helper function to check for palindromes
bool is_palindrome(int n) {
    string s = to_string(n);
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

// Pre-compute all palindromes and the DP table once
void precompute() {
    for (int i = 1; i < MAXN; i++) {
        if (is_palindrome(i)) {
            palindromes.push_back(i);
        }
    }

    dp[0] = 1;
    // Correct loop order for combinations
    for (int p : palindromes) {
        for (int i = p; i < MAXN; i++) {
            // Apply modulo at each step
            dp[i] = (dp[i] + dp[i - p]) % MOD;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    // The answer is already computed, just print it
    cout << dp[n] << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Run the expensive computation only once
    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}