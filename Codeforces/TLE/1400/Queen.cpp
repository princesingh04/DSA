#include <iostream>
#include <vector>
#include <algorithm>

// Using std namespace for competitive programming
using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // --- Setup Phase ---
    // Adjacency list to store the tree (parent -> children)
    vector<vector<int>> adj(n + 1);
    // Boolean array to store the rebel status of each vertex
    vector<bool> rebel(n + 1, false);
    int root = -1;

    // Correctly read the input for each vertex i
    for (int i = 1; i <= n; ++i) {
        int p, c;
        cin >> p >> c;

        if (p == -1) {
            root = i;
        } else {
            adj[p].push_back(i);
        }

        if (c == 1) {
            rebel[i] = true;
        }
    }

    // --- Finding Candidates Phase ---
    vector<int> ans;

    // Check every vertex from 1 to n
    for (int i = 1; i <= n; ++i) {
        // Condition 1: The vertex itself must be rebellious.
        if (rebel[i]) {
            bool all_children_rebellious = true;
            
            // Condition 2: Check all of its direct children.
            for (int child : adj[i]) {
                if (!rebel[child]) {
                    // Found a respectful child, so this parent is "protected".
                    all_children_rebellious = false;
                    break; // No need to check other children
                }
            }

            // If the vertex is rebellious AND all its children are rebellious...
            if (all_children_rebellious) {
                // ...it's a candidate for deletion.
                ans.push_back(i);
            }
        }
    }

    // --- Output Phase ---
    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        // The problem asks to delete the one with the smallest number first,
        // so we sort our list of candidates.
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}