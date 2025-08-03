#include <iostream>
#include <vector>
#include <queue> // Required for priority_queue

void solve() {
    int n;
    std::cin >> n;

    long long current_health = 0;
    
    // A min-priority queue to store the values of potions we have drunk.
    // The smallest (most negative) potion value will always be at the top.
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> potions_drunk;

    for (int i = 0; i < n; ++i) {
        long long potion_val;
        std::cin >> potion_val;

        // Step 1: Always try to drink the current potion.
        current_health += potion_val;
        potions_drunk.push(potion_val);

        // Step 2: If health becomes negative, we must fix it.
        // We "undrink" the most harmful potion taken so far to recover health.
        if (current_health < 0) {
            // Get the most harmful potion (the one with the smallest value).
            long long most_harmful_potion = potions_drunk.top();
            
            // Remove its effect from our health.
            current_health -= most_harmful_potion; // Subtracting a negative value increases health.
            
            // Permanently remove it from our set of drunk potions.
            potions_drunk.pop();
        }
    }

    // The answer is the total number of potions we were able to keep.
    std::cout << potions_drunk.size() << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}