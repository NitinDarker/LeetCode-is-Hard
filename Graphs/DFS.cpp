// Depth-First Search
#include <bits/stdc++.h>
using namespace std;

void DFS(const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &res, int node) {
    visited[node] = true;
    res.push_back(node);

    // Traversing the adjacency list of current node
    for (const int &nei : adj[node]) {
        if (!visited[nei]) {
            DFS(adj, visited, res, nei);
        }
    }
}

vector<int> dfsOfGraph(const vector<vector<int>> &adj) {
    int n = adj.size();

    vector<bool> visited(n, false); // Visited Array
    vector<int> res;                // Result Array

    int start = 0; // Starting from node 0
    DFS(adj, visited, res, start);

    return res;
}
// Time Complexity = O(n) + O(2*E)

int main() {
    // Example graph (Adjacency List Representation)
    vector<vector<int>> adj = {
        {1, 2},    // Node 0 is connected to 1, 2
        {0, 3, 4}, // Node 1 is connected to 0, 3, 4
        {0, 5},    // Node 2 is connected to 0, 5
        {1},       // Node 3 is connected to 1
        {1, 5},    // Node 4 is connected to 1, 5
        {2, 4}     // Node 5 is connected to 2, 4
    };

    vector<int> dfs_result = dfsOfGraph(adj);

    cout << "DFS Traversal: ";
    for (int node : dfs_result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
