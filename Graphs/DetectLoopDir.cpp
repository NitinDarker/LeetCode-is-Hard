// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int V, vector<vector<int>> &edges) {
    vector<vector<int>> graph(V + 1);
    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i][0], b = edges[i][1];
        graph[a].push_back(b);
    }
    return graph;
}

// Using a path-visited Array
bool DFS(int node, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> &graph) {
    vis[node] = true;
    pathVis[node] = true;
    for (int nei : graph[node]) {
        if (!vis[nei] && DFS(nei, vis, pathVis, graph))
            return true;
        else if (vis[nei] && pathVis[nei])
            return true;
    }
    pathVis[node] = false;
    return false;
}

// Using Kahn's Algorithm
bool bfs(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (int nei : graph[i]) {
            inDegree[nei]++;
        }
    }
    queue<int> q;
    vector<int> topo;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (int nei : graph[node]) {
            inDegree[nei]--;
            if (inDegree[nei] == 0)
                q.push(nei);
        }
    }
    return !(topo.size() == V);
}

// Detection of cycle/loop in an directed graph
bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> graph = createGraph(V, edges);
    vector<bool> vis(V + 1, false), pathVis(V + 1, false);
    for (int i = 1; i <= V; i++) {
        if (!vis[i] && DFS(i, vis, pathVis, graph)) {
            return true;
        }
    }
    return false;
    // return bfs(graph);
}
