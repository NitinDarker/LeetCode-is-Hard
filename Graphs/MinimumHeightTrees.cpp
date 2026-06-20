// https://leetcode.com/problems/minimum-height-trees/description/
#include <bits/stdc++.h>
using namespace std;

// Using Topological Sort -> Kahn's Algorithm
class Solution {
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0};
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        int leftNodes = n;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] <= 1) q.push(i);
        }

        // BFS -> Level Order Traversal
        while (!q.empty()) {
            if (leftNodes <= 2) break;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int node = q.front(); q.pop();
                leftNodes--;
    
                for (int nei : graph[node]) {
                    if (--degree[nei] == 1) {
                        q.push(nei);
                    }
                }
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
