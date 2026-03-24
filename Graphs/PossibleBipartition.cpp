// https://leetcode.com/problems/possible-bipartition/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool colorBFS(int start, vector<vector<int>> &graph, vector<int> &color) {
        queue<int> q;
        q.push(start);
        color[start] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int c = color[node];
            for (int nei : graph[node]) {
                if (color[nei] == -1) {
                    color[nei] = !c;
                    q.push(nei);
                } else if (color[nei] == c) {
                    return false;
                }
            }
        }
        return true;
    }

  public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        vector<vector<int>> graph(n+1);
        for (vector<int> &dis : dislikes) {
            int a = dis[0], b = dis[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> color(n+1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1 && !colorBFS(i, graph, color)) return false;
        }
        return true;
    }
};
