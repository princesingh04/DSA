#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> diff_array(n + 2, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        diff_array[a]++;
        diff_array[b + 1]--;
    }

    int current_count = 0;
    for (int d = 1; d <= n; ++d) {
        current_count += diff_array[d];
        if (current_count != 1) {
            std::cout << d << " " << current_count << "\n";
            return;
        }
    }

    std::cout << "OK\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t = 1; // The problem statement format is usually t test cases.
               // However, the example shows only one t=1, then n, m.
               // For this specific problem, let's assume it's one test case per run.
               // Let's re-read the input... "The first input line contains two numbers n and m".
               // The examples also don't show a `t` value on the first line.
               // So, let's assume `main` should run solve() only once.

    // A correct main loop for competitive programming would be:
    // int t; std::cin >> t; while(t--) solve();
    // But since the problem description seems to imply a single input, we'll follow that structure.
    solve();

    return 0;
}