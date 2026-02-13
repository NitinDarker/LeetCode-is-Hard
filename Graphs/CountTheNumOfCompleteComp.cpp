// https://leetcode.com/problems/count-the-number-of-complete-components/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool bfs(int start, vector<vector<int>> &graph, vector<bool> &vis) {
        int n = graph.size();
        queue<int> q;
        q.push(start);
        vis[start] = true;
        int nodes = 1, edges = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nei : graph[node]) {
                edges++;
                if (!vis[nei]) {
                    q.push(nei);
                    vis[nei] = true;
                    nodes++;
                }
            }
        }
        if (nodes * (nodes-1) == edges) return true;
        return false;
    }

  public:
    int countCompleteComponents(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n);
        for (vector<int> &edg : edges) {
            graph[edg[0]].push_back(edg[1]);
            graph[edg[1]].push_back(edg[0]);
        }
        vector<bool> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt += bfs(i, graph, vis);
            }
        }
        return cnt;
    }
};
