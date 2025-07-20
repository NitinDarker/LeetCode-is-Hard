// Level Order Traversal -> Breadth-First Search
#include <bits/stdc++.h>
using namespace std;

// Printing all the nodes in BFS fashion
void bfs(vector<vector<int>> &graph) {
    // Graph is provided in the form of an Adjacency List (1-based Indexing)
    vector<int> visited(graph.size(), 0);
    queue<int> q;

    // 1-based Indexing
    q.push(1); // Starting Node = 1
    visited[1] = 1;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        cout << top << " ";

        for (int i = 0; i < graph[top].size(); i++) {
            int node = graph[top][i];
            if (visited[node] == 0) {
                q.push(graph[top][i]);
                visited[node] = 1;
            }
        }
    }
    cout << endl;
}

// Returning output as a list
vector<int> bfsOfGraph(vector<vector<int>> &graph) {
    vector<int> visited(graph.size(), 0);
    vector<int> res;
    queue<int> q;

    // 0-Based Indexing
    q.push(0); // Starting Node = 0
    visited[0] = 1;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        res.push_back(top);

        for (int i = 0; i < graph[top].size(); i++) {
            int node = graph[top][i];
            if (visited[node] == 0) {
                q.push(node);
                visited[node] = 1;
            }
        }
    }
    return res;
}

int main() {
    // Example graph (1-based indexing)
    vector<vector<int>> graph = {
        {},        // 0 (unused)
        {2, 3},    // 1 -> 2, 3
        {1, 4, 5}, // 2 -> 1, 4, 5
        {1, 6},    // 3 -> 1, 6
        {2},       // 4 -> 2
        {2},       // 5 -> 2
        {3}        // 6 -> 3
    };
    bfs(graph); // Expected BFS order: 1 2 3 4 5 6
    return 0;
}