// https://leetcode.com/problems/01-matrix/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> dist(n, vector<int> (m, 0));
        queue<pair<pair<int,int>, int>> q;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }

        // BFS
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int x = curr.first.first, y = curr.first.second;
            int d = curr.second;
            dist[x][y] = d;

            for (int k = 0; k < 4; k++) {
                int nrow = x + dx[k], ncol = y + dy[k];
                if (nrow >= 0 && nrow < n && 
                    ncol >= 0 && ncol < m && 
                    !visited[nrow][ncol]) {
                    q.push({{nrow, ncol}, d+1});
                    visited[nrow][ncol] = true;
                }
            }
        }
        return dist;
    }
};
