// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<pair<int, int>>> graph; // node -> [{node, cost}]
        for (auto &edg : edges) {
            int u = edg[0], v = edg[1], w = edg[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w}); // Undirected graph
        }

        // [cost, node]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<int> dist(V, 1e9);

        heap.push({0, src});
        dist[src] = 0;

        while (!heap.empty()) {
            int cur = heap.top().second, curCost = heap.top().first;
            heap.pop();
            if (curCost > dist[cur]) continue;
            for (auto &nei : graph[cur]) {
                int nextNode = nei.first, nextCost = nei.second;
                int totalCost = nextCost + curCost;
                if (dist[nextNode] > totalCost) {
                    dist[nextNode] = totalCost;
                    heap.push({totalCost, nextNode});
                }
            }
        }
        return dist;
    }
};
