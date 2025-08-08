#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    // Fast I/O for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 1. Read the number of cities
    int n;
    std::cin >> n;

   
    
    // 2. Create the map to store sums
    // Key: (city_number - beauty_value). This is our "grouping key".
    // Value: The running sum of beauties for all cities in that group.
    // We use `long long` for the sum because it can exceed the limit of a 32-bit integer.
    std::unordered_map<int, long long> beauty_sums;

    // 3. Process each city
    for (int i = 0; i < n; ++i) {
        int current_beauty;
        std::cin >> current_beauty;

        // The city number is (i + 1) since loops are 0-indexed.
        int key = (i + 1) - current_beauty;
        
        // Add the current city's beauty to the total for its group.
        // If the key doesn't exist yet, it's created and initialized to 0 before adding.
        beauty_sums[key] += current_beauty;
    }

    // 4. Find the maximum beauty sum
    long long max_beauty = 0;

    // A journey can have just one city, and all beauty values are positive (>= 1).
    // So, if n > 0, the max_beauty will be at least 1.
    // If n = 0 (not possible by constraints, but good practice), the answer is 0.

    // Iterate through all the calculated sums in the map.
    // `pair.second` holds the total beauty for a group.
    for (const auto& pair : beauty_sums) {
        if (pair.second > max_beauty) {
            max_beauty = pair.second;
        }
        // A shorter way to write the above if-statement:
        // max_beauty = std::max(max_beauty, pair.second);
    }

    // 5. Print the result
    std::cout << max_beauty << std::endl;

    return 0;
}