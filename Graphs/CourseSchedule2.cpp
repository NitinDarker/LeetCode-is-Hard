// https://leetcode.com/problems/course-schedule-ii/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> createGraph(int V, vector<vector<int>> &pre) {
        vector<vector<int>> graph(V);
        for (int i = 0; i < pre.size(); i++) {
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        return graph;
    }

    // Using Kahn's Algorithm
    vector<int> bfs(vector<vector<int>> &graph) {
        int V = graph.size();
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int nei : graph[i]) {
                inDegree[nei]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (int nei : graph[node]) {
                inDegree[nei]--;
                if (inDegree[nei] == 0)
                    q.push(nei);
            }
        }
        if (topo.size() != V) return {};
        return topo;
    }

  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph = createGraph(numCourses, prerequisites);
        return bfs(graph);
    }
};
