// https://leetcode.com/problems/is-graph-bipartite/description/
#include <bits/stdc++.h>
using namespace std;

// BFS
class Solution {
    bool BFS(int start, vector<vector<int>> &graph, vector<int> &vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nei : graph[node]) {
                if (vis[nei] == -1) {
                    q.push(nei);
                    vis[nei] = !vis[node];
                } else if (vis[nei] == vis[node]) {
                    return false;
                }
            }
        }
        return true;
    }

  public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1 && !BFS(i, graph, vis))
                return false;
        }
        return true;
    }
};

// DFS
class Solution {
    bool DFS(int node, vector<int> &vis, vector<vector<int>> &graph) {
        for (int nei : graph[node]) {
            if (vis[nei] == -1) {
                vis[nei] = !vis[node];
                if (!DFS(nei, vis, graph))
                    return false;
            } else if (vis[nei] == vis[node]) {
                return false;
            }
        }
        return true;
    }

  public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        vis[0] = 0;
        if (!DFS(0, vis, graph))
            return false;
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1 && !DFS(i, vis, graph)) {
                return false;
            }
        }
        return true;
    }
};
