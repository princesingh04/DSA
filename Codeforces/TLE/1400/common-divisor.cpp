#include <bits/stdc++.h>
using namespace std;

// Function to repeat a string 'times' times
string repeatStr(const string &s, int times) {
    string res;
    res.reserve(s.size() * times);
    for (int i = 0; i < times; i++) res += s;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.size(), n2 = s2.size();
    int g = __gcd(n1, n2); // Step 1: GCD of lengths

    string base = s1.substr(0, g);

    // Step 2: Verify base can generate both strings
    if (repeatStr(base, n1 / g) != s1 || repeatStr(base, n2 / g) != s2) {
        cout << 0 << "\n";
        return 0;
    }

    // Step 3: Count divisors of g that divide the pattern
    int ans = 0;
    for (int d = 1; d * d <= g; d++) {
        if (g % d == 0) {
            // Check divisor d
            string sub1 = base.substr(0, d);
            if (repeatStr(sub1, g / d) == base) ans++;

            // Check divisor g/d if distinct
            if (d * d != g) {
                int d2 = g / d;
                string sub2 = base.substr(0, d2);
                if (repeatStr(sub2, g / d2) == base) ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
