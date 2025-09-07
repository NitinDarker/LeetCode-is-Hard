// https://leetcode.com/problems/rotting-oranges/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<pair<int,int>,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }
        vector<int> delX = {-1, 0, 1, 0};
        vector<int> delY = {0, 1, 0, -1};
        int time = 0;
        while (!q.empty()) {
            int x = q.front().first.first, y = q.front().first.second;
            time = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int i = x + delX[k], j = y + delY[k];
                if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j]) {
                    continue;
                }
                q.push({{i, j},time+1});
                vis[i][j] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }
        return time;
    }
};
