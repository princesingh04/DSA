#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Check if the string contains both directions
        bool hasLeft = false, hasRight = false;
        for (char c : s) {
            if (c == '<') hasLeft = true;
            if (c == '>') hasRight = true;
        }

        // Case 1: Only one direction (or only '-'s)
        if (!hasLeft || !hasRight) {
            cout << n << "\n";
            continue;
        }

        // Case 2: Both '<' and '>' exist, count rooms adjacent to '-'
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '-' || s[(i - 1 + n) % n] == '-') {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
