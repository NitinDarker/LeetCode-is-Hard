// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include <bits/stdc++.h>
using namespace std;

// Using Prim's Algorithm
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> graph(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // pq <- {wt, {node, parent}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, -1}});

        vector<int> vis(V, 0);
        vector<pair<int, int>> mst; // Stores edges of MST
        int sum = 0;                // Edge weight Sum

        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int cost = it.first;
            int node = it.second.first;
            int parent = it.second.second;

            if (vis[node]) continue; // Lazy Deletion
            vis[node] = 1;
            mst.push_back({parent, node});
            sum += cost;

            for (auto &[nei, wt] : graph[node]) {
                if (!vis[nei]) pq.push({wt, {nei, node}});
            }
        }

        return sum;
        // MST array contains all the edges of MST
    }
};
