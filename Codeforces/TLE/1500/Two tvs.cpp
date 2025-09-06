#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Fast I/O for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 1. Create a vector to store the events.
    // Each event is a pair: {time, type}. type is +1 for start, -1 for end.
    std::vector<std::pair<int, int>> events;

    // 2. Populate the events list from the input.
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        events.push_back({l, 1});  // +1 for a show starting
        events.push_back({r, -1}); // -1 for a show ending
    }

    // 3. Sort the events.
    // The custom lambda function handles the tie-breaking rule.
    std::sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first) {
            // Primary sort: by time
            return a.first < b.first;
        }
        // Secondary sort: process starts (+1) before ends (-1)
        return a.second > b.second;
    });

    // 4. Sweep through the events and count.
    int current_shows = 0;
    bool possible = true;

    for (const auto& event : events) {
        current_shows += event.second; // Add +1 for a start, -1 for an end
        
        // Check if the number of concurrent shows exceeds 2
        if (current_shows > 2) {
            possible = false;
            break; // We found a conflict, no need to check further
        }
    }

    if (possible) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}