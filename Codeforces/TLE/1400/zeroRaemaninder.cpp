#include <bits/stdc++.h>
using namespace std;

long long solveOne(vector<long long>& a, long long k) {
    map<long long, long long> freq;
    
    for (long long x : a) {
        long long r = (k - x % k) % k;
        if (r != 0) freq[r]++;
    }

    long long ans = 0;
    for (auto it : freq) {
        int r= it.first;
        int f = it.second;
        // last x for this remainder group
        long long last_x = r + (f - 1) * k;
        ans = max(ans, last_x);
    }

    return (freq.empty() ? 0 : ans + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solveOne(a, k) << "\n";
    }
    return 0;
}
