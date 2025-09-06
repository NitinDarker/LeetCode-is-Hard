// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // O(V + 2E)
    vector<int> shortestPath(vector<vector<int>> &adj, int src) {
        int V = adj.size();
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int cur = q.front();
            int d = dist[cur];
            q.pop();
            for (int nei : adj[cur]) {
                if (d+1 < dist[nei]) {
                    dist[nei] = d+1;
                    q.push(nei);
                }
            }
        }
        for (int &it : dist) {
            if (it == 1e9) {
                it = -1;
            }
        }
        return dist;
    }
};
