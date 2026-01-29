// https://leetcode.com/problems/minimum-cost-to-convert-string-i/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<long long>> createGraph(vector<char> &a, vector<char> &b, vector<int> &cost) {
        int n = a.size();
        vector<vector<long long>> adj(26, vector<long long>(26, INT_MAX)); // Adjacency Matrix
        for (int i = 0; i < 26; i++) {
            adj[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int u = a[i] - 'a', v = b[i] - 'a';
            adj[u][v] = min((long long)cost[i], adj[u][v]);
        }
        return adj;
    }

  public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost) {
        vector<vector<long long>> graph = createGraph(original, changed, cost);

        // Floyd Warshall
        vector<vector<long long>> dist(graph.begin(), graph.end());
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int m = source.size();
        long long minCost = 0;
        for (int i = 0; i < m; i++) {
            int u = source[i] - 'a', v = target[i] - 'a';
            if (dist[u][v] >= INT_MAX) return -1;
            minCost += dist[u][v];
        }
        return minCost;
    }
};
