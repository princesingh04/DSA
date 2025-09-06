#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

void solve() {
    int n, k1, k2;
    std::cin >> n >> k1 >> k2;

    int total_ops = k1 + k2;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];

    // 1. Initialize the max-heap with the absolute differences
    std::priority_queue<long long> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(std::abs(a[i] - b[i]));
    }

    // 2. Perform the k operations
    for (int i = 0; i < total_ops; ++i) {
        long long top = pq.top();
        pq.pop();

        // If the biggest difference is 0, an operation will make it 1.
        // Otherwise, decrease the biggest difference by 1.
        if (top == 0) {
            pq.push(1);
        } else {
            pq.push(top - 1);
        }
    }

    // 3. Calculate the final error
    long long final_error = 0;
    while (!pq.empty()) {
        long long d = pq.top();
        pq.pop();
        final_error += d * d;
    }

    std::cout << final_error << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}