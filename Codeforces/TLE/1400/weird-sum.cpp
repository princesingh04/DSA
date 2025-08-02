#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    // Use maps to group row and column coordinates by their color
    std::map<int, std::vector<int>> rows_by_color;
    std::map<int, std::vector<int>> cols_by_color;

    // Read the grid and populate the maps
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int color;
            std::cin >> color;
            rows_by_color[color].push_back(i);
            cols_by_color[color].push_back(j);
        }
    }

    // Use long long for the total sum to prevent overflow
    long long total_weird_sum = 0;

    // Iterate through each color group to calculate the sum of distances
    // Use `auto&` to get a mutable reference to the map's value (the vector)
    for (auto& pair : rows_by_color) {
        int color = pair.first;
        
        // Get references to the coordinate vectors for the current color
        std::vector<int>& rows = pair.second;
        std::vector<int>& cols = cols_by_color[color];

        long long k = rows.size();

        // The distance sum is non-zero only if there are 2 or more points
        if (k > 1) {
            // Sort coordinates to apply the linear-time formula
            std::sort(rows.begin(), rows.end());
            std::sort(cols.begin(), cols.end());

            // Calculate sum of differences for rows and columns
            for (long long i = 0; i < k; ++i) {
                // Formula: sum(coord[i] * (2*i - k + 1))
                // Use 2LL to promote the multiplication to long long
                total_weird_sum += (long long)rows[i] * (2LL * i - k + 1);
                total_weird_sum += (long long)cols[i] * (2LL * i - k + 1);
            }
        }
    }

    std::cout << total_weird_sum << std::endl;

    return 0;
}