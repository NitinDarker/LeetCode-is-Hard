https://leetcode.com/problems/critical-connections-in-a-network/description/
// To find bridges in a graph
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> bridges;

    vector<vector<int>> createAdj(int V, const vector<vector<int>> &edges) {
        vector<vector<int>> adj(V); // Adjacency List
        for (vector<int> edg : edges) {
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);
        }
        return adj;
    }

    void DFS_tarjan(int start, int parent, int &step, const vector<vector<int>> &adj, vector<int> &visited, vector<int> &steps, vector<int> &low) {
        steps[start] = step;
        low[start] = step;
        for (int nei : adj[start]) {
            if (!visited[nei]) {
                visited[nei] = 1;
                DFS_tarjan(nei, start, ++step, adj, visited, steps, low);
            }
            if (nei != parent) {
                low[start] = min(low[start], low[nei]);
                // wtf is this logic!! Who came up with this first....
                if (steps[start] < low[nei]) {
                    bridges.push_back({start, nei});
                }
            }
            // Can't believe this actually runs. I am proud of myself :')
        }
    }

  public:
    vector<vector<int>> criticalConnections(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj = createAdj(V, edges);
        vector<int> visited(V, 0), steps(V, 0), low(V, 0);
        steps[0] = 0;
        low[0] = 0;
        int step = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                visited[i] = 1;
                DFS_tarjan(i, -1, ++step, adj, visited, steps, low);
            }
        }
        return bridges;
    }
};
