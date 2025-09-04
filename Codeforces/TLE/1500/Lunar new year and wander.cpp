#include <iostream>
#include <vector>
#include <queue>
#include <functional> // Required for std::greater

void solve() {
    int n, m;
    std::cin >> n >> m;

    // Use an adjacency list to represent the graph
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // A min-priority queue to always keep the smallest-numbered
    // available node at the top.
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    
    std::vector<bool> visited(n + 1, false);
    std::vector<int> result_sequence;

    // 1. Start the process at node 1
    pq.push(1);

    // 2. Main traversal loop
    while (!pq.empty()) {
        // Get the smallest available node
        int u = pq.top();
        pq.pop();

        // If we have already processed this node, skip it.
        // This handles cases where a node is added to the queue multiple times.
        if (visited[u]) {
            continue;
        }

        // Process the node: mark it visited and add it to our final sequence
        visited[u] = true;
        result_sequence.push_back(u);

        // Add all of its unvisited neighbors to the queue as candidates
        for (int v : adj[u]) {
            if (!visited[v]) {
                pq.push(v);
            }
        }
    }

    // 3. Print the final result
    for (int i = 0; i < result_sequence.size(); ++i) {
        std::cout << result_sequence[i] << (i == result_sequence.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    solve();

    return 0;
}