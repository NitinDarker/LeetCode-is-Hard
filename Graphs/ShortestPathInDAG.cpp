#include <bits/stdc++.h>
using namespace std;

// Using Topological Sort -> Only for DAG(No cycles)
class Solution {
    vector<vector<pair<int,int>>> createGraph(int V, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>> graph(V);
        for (vector<int> &edg : edges) {
            graph[edg[0]].push_back({edg[1], edg[2]});
        }
        return graph;
    }

    void topoDFS(int cur, vector<vector<pair<int,int>>> &graph, vector<bool> &vis, stack<int> &st) {
        vis[cur] = true;
        for (pair<int, int> nei : graph[cur]) {
            if (!vis[nei.first]) {
                topoDFS(nei.first, graph, vis, st);
            }
        }
        st.push(cur);
    }

  public:
    // O(V+E)
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>> graph = createGraph(V, edges);
        
        // Topological Sort
        stack<int> st;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoDFS(i, graph, vis, st);
            }
        }

        // Shortest path
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            int currdist = dist[cur];
            for (pair<int, int> nei : graph[cur]) {
                int newDist = currdist + nei.second;
                dist[nei.first] = min(dist[nei.first], newDist);
            }
        }

        for (int &d : dist) {
            if (d == 1e9) d = -1;
        }
        return dist;
    }
};
