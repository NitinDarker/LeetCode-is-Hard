// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> graph(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], c = edge[2];
            graph[u].push_back({v, c});
            graph[v].push_back({u, c});
        }

        // pq <- {cost, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            // Lazy pruning
            if (cost > dist[node]) continue;

            for (auto &[nei, weight] : graph[node]) {
                if (cost + weight < dist[nei]) {
                    dist[nei] = cost + weight;
                    pq.push({cost + weight, nei});
                }
            }
        }
        return dist;
    }
};
