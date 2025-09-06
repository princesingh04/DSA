#include <iostream>
#include <vector>
#include <functional> // Although not strictly needed, it's good practice for modern C++

// Adjacency list to represent the tree
std::vector<std::vector<int>> adj;
// Global counter for the number of valid cuts
int cuts = 0;

/**
 * @brief Performs a DFS to calculate subtree sizes.
 * * @param u The current node being visited.
 * @param p The parent of the current node (to avoid going backward).
 * @return The size of the subtree rooted at node u.
 */
int dfs(int u, int p) {
    // The size of the subtree is at least 1 (for the node u itself).
    int subtree_size = 1;

    // Explore all neighbors of u
    for (int v : adj[u]) {
        // Skip the neighbor if it's the parent we just came from
        if (v == p) {
            continue;
        }

        // Recursively find the size of the child's subtree
        int child_subtree_size = dfs(v, u);

        // This is the core logic:
        // If the child's subtree has an even number of nodes...
        if (child_subtree_size % 2 == 0) {
            // ...then the edge connecting u and v can be cut.
            cuts++;
        }
        
        // Add the child's subtree size to the current node's total
        subtree_size += child_subtree_size;
    }

    return subtree_size;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 1. Handle the impossible case: total number of vertices is odd.
    if (n % 2 != 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    // 2. Build the tree using an adjacency list.
    // We resize to n+1 to use 1-based indexing easily.
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 3. Start the DFS from node 1. The parent of the root is a dummy value (e.g., 0).
    dfs(1, 0);

    // 4. Print the final count of possible cuts.
    std::cout << cuts << std::endl;

    return 0;
}