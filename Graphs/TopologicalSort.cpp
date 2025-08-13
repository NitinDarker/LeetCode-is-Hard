// https://www.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>
using namespace std;

// Edges -> Adjacency List
vector<vector<int>> createAdj(const vector<vector<int>> &edges, const int V) {
    vector<vector<int>> adj(V);
    for (vector<int> edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }
    return adj;
}

// DFS (Topological Sort Algorithm)
void dfs(int start, const vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[start] = true;
    for (int node : adj[start]) {
        if (!visited[node]) dfs(node, adj, visited, st);
    }
    st.push(start);
}

// BFS (Kahn's Algorithm)
vector<int> bfs(vector<vector<int>> &adj) {
    int V = adj.size();
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (int nei : adj[i]) {
            inDegree[nei]++;
        }
    }
    queue<int> q;
    vector<int> topo;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int node = q.front(); q.pop();
        topo.push_back(node);
        for (int nei : adj[node]) {
            inDegree[nei]--;
            if (inDegree[nei] == 0) q.push(nei);
        }
    }
    return topo;
}

vector<int> topoSort(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj = createAdj(edges, V);
    stack<int> st;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    vector<int> sorted;
    while (!st.empty()) {
        sorted.push_back(st.top());
        st.pop();
    }
    return sorted;
    // return bfs(adj);
}
