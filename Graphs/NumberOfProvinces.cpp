// https://leetcode.com/problems/number-of-provinces/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(vector<vector<int>> &matrix, vector<int> &visited, int start) {
        int n = matrix.size();
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                if (matrix[node][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

  public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        int res = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(isConnected, visited, i);
                res++;
            }
        }
        return res;
    }
};
