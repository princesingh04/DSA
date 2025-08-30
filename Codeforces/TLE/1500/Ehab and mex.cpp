#include <iostream>
#include <vector>
#include <numeric>
 
int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
 
    int n;
    std::cin >> n;
 
    // Store edges to process later, as we need node degrees first.
    // Each element is a pair {u, v} representing an edge.
    std::vector<std::pair<int, int>> edges;
    // Store the degree of each node. Size n+1 for 1-based indexing.
    std::vector<int> degree(n + 1, 0);
 
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        edges.push_back({u, v});
        degree[u]++;
        degree[v]++;
    }
 
    // This vector will store the final labels in the input order.
    std::vector<int> labels(n - 1, -1);
    
    // Two pointers for assigning labels.
    int low_label = 0;
    int high_label = n - 2;
 
    // Iterate through the edges in the order they were given.
    for (int i = 0; i < n - 1; ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
 
        // Check if this is a leaf edge (connected to a node of degree 1).
        if (degree[u] == 1 || degree[v] == 1) {
            labels[i] = low_label;
            low_label++;
        }
    }
    
    // Assign high labels to the remaining (central) edges.
    for (int i = 0; i < n - 1; ++i) {
        if (labels[i] == -1) {
            labels[i] = high_label;
            high_label--;
        }
    }
 
    // Print the final labels.
    for (int i = 0; i < n - 1; ++i) {
        std::cout << labels[i] << "\n";
    }
 
    return 0;
}