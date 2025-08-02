// https://leetcode.com/problems/number-of-enclaves/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<int> dx = {-1, 0, 1, 0};
    const vector<int> dy = {0, -1, 0, 1};

    void dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || vis[x][y]) return;
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) dfs(x+dx[i], y+dy[i], vis, grid);
    }

  public:
    int numEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != 0 && i != n-1 && j != 0 && j != m-1) continue;
                if (grid[i][j] == 1 && !vis[i][j]) dfs(i, j, vis, grid);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};
