#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long n, m;
        cin >> n >> m;

        long long cnt2 = 0, cnt5 = 0;

        // Count powers of 2 in n
        long long temp = n;
        while (temp % 2 == 0) {
            cnt2++;
            temp /= 2;
        }

        // Count powers of 5 in n
        temp = n;
        while (temp % 5 == 0) {
            cnt5++;
            temp /= 5;
        }

        long long k = 1;

        // Step 1: Balance 2s and 5s to maximize trailing zeros
        while (cnt2 < cnt5 && k * 2 <= m) {
            k *= 2;
            cnt2++;
        }
        while (cnt5 < cnt2 && k * 5 <= m) {
            k *= 5;
            cnt5++;
        }

        // Step 2: Multiply by 10 as much as possible
        while (k * 10 <= m) {
            k *= 10;
        }

        // Step 3: Scale up to the maximum multiplier <= m
        k *= (m / k);

        // Step 4: Final answer
        cout << n * k << "\n";
    }

    return 0;
}
