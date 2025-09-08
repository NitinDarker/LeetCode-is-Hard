// https://leetcode.com/problems/find-eventual-safe-states/
#include <bits/stdc++.h>
using namespace std;

// DFS -> Cycle Detection in Directed Graph
class Solution {
    bool DFS(int node, vector<bool> &vis, vector<bool> &pathVis, vector<bool> &safe, vector<vector<int>> &graph, int V) {
        vis[node] = true;
        pathVis[node] = true;
        for (int nei : graph[node]) {
            if (!vis[nei] && DFS(nei, vis, pathVis, safe, graph, V))
                return true;
            else if (vis[nei] && pathVis[nei])
                return true;
        }
        safe[node] = true;
        pathVis[node] = false;
        return false;
    }

  public:
    vector<int> eventualSafeNodes(vector<vector<int>> graph) {
        int V = graph.size();
        vector<bool> vis(V, false), pathVis(V, false), safe(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i])
                DFS(i, vis, pathVis, safe, graph, V);
        }
        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (safe[i])
                res.push_back(i);
        }
        return res;
    }
};

// BFS -> Using Topological Sort (Kahn's Algorithm)
class Solution {
    vector<vector<int>> reverseGraph(vector<vector<int>> &graph) {
        int V = graph.size();
        vector<vector<int>> rev(V);
        for (int i = 0; i < V; i++) {
            for (int nei : graph[i]) {
                rev[nei].push_back(i);
            }
        }
        return rev;
    }

    vector<int> topoSort(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int nei : adj[i]) {
                inDegree[nei]++;
            }
        }
        queue<int> q;
        vector<int> safe;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for (int nei : adj[node]) {
                inDegree[nei]--;
                if (inDegree[nei] == 0) q.push(nei);
            }
        }
        return safe;
    }

  public:
    vector<int> eventualSafeNodes(vector<vector<int>> graph) {
        int V = graph.size();
        vector<vector<int>> revGraph = reverseGraph(graph);
        vector<int> safe = topoSort(revGraph);
        sort(safe.begin(), safe.end());
        return safe;
    }
};
