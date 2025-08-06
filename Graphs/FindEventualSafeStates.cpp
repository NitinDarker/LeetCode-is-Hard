// https://leetcode.com/problems/find-eventual-safe-states/
#include <bits/stdc++.h>
using namespace std;

// DFS -> Cycle Detection in Directed Graph
class Solution {
    bool DFS(int node, vector<bool> &vis, vector<bool> &pathVis, vector<bool> &safe, vector<vector<int>> &graph, int V) {
        vis[node] = true;
        pathVis[node] = true;
        for (int nei : graph[node]) {
            if (!vis[nei] && DFS(nei, vis, pathVis, safe, graph, V)) return true;
            else if (vis[nei] && pathVis[nei]) return true;
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
            if (!vis[i]) DFS(i, vis, pathVis, safe, graph, V);
        }
        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (safe[i]) res.push_back(i);
        }
        return res;
    }
};
