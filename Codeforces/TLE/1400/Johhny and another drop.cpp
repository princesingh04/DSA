#include <iostream>

void solve() {
    long long n;
    std::cin >> n;

    long long total_unfairness = 0;

    // This loop implements your logic perfectly.
    // p will be 1, 2, 4, 8, ...
    for (long long p = 1; p <= n; p *= 2) {
        total_unfairness += n / p;
    }

    std::cout << total_unfairness << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}