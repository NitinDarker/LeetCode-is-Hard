// https://leetcode.com/problems/cheapest-flights-within-k-stops/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto &edge : flights) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
        }

        // q <- {stops, {dist, node}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, src}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front(); q.pop();
            int stops = it.first;
            int cost = it.second.first;
            int node = it.second.second;

            for (auto &[nei, weight] : graph[node]) {
                int newDist = cost + weight;
                if (stops + 1 < k && newDist < dist[nei]) {
                    dist[nei] = newDist;
                    q.push({stops + 1, {newDist, nei}});
                }
            }
        }

        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
