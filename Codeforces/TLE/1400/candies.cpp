#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];

    // prefix sum
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + s[i];

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        long long sum = pre[r] - pre[l - 1];
        cout << sum / 10 << "\n";
    }

    return 0;
}
