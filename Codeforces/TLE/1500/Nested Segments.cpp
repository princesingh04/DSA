#include <iostream>
#include <vector>
#include <algorithm>

// A struct to hold the segment data and its original index
struct Segment {
    int l, r, id;
};

// Custom sorting function (can also be a lambda)
bool compareSegments(const Segment& a, const Segment& b) {
    // Primary sort key: start point ascending
    if (a.l != b.l) {
        return a.l < b.l;
    }
    // Secondary sort key: end point descending
    return a.r > b.r;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Segment> segments(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> segments[i].l >> segments[i].r;
        segments[i].id = i + 1; // Store the original 1-based index
    }

    // Sort using the custom comparison function
    std::sort(segments.begin(), segments.end(), compareSegments);

    // This will track the best "container" segment found so far
    Segment best_container = segments[0];

    // Iterate from the second segment to find one that fits
    for (int i = 1; i < n; ++i) {
        Segment current_segment = segments[i];

        // Check the nested condition
        if (current_segment.r <= best_container.r) {
            // Found a solution!
            std::cout << current_segment.id << " " << best_container.id << std::endl;
            return 0; // Exit
        } else {
            // This segment is a better potential container because its right end extends further
            best_container = current_segment;
        }
    }

    // If the loop finishes, no solution was found
    std::cout << -1 << " " << -1 << std::endl;

    return 0;
}