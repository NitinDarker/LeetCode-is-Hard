// https://leetcode.com/problems/minimum-height-trees/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>> &edges) {
        if (V == 1) return {0};
        vector<vector<int>> graph(V);
        vector<int> degree(V, 0);
        for (vector<int> &edg : edges) {
            graph[edg[0]].push_back(edg[1]);
            graph[edg[1]].push_back(edg[0]);
            degree[edg[0]]++;
            degree[edg[1]]++;
        }
        
        int remNodes = V;
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) q.push(i);
        }
        while (!q.empty() && remNodes > 2) {
            int size = q.size();
            remNodes -= size;
            for (int i = 0; i < size; i++) {
                int node = q.front();
                for (int nei : graph[node]) {
                    degree[nei]--;
                    if (degree[nei] == 1) q.push(nei);
                }
                q.pop();
            }
        }
        vector<int> root;
        while (!q.empty()) {
            root.push_back(q.front());
            q.pop();
        }
        return root;
    }
};
