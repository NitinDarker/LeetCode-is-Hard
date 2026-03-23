// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // left-down-right-up
    vector<int> dirX = {-1, 0, 1, 0};
    vector<int> dirY = {0, -1, 0, 1};

    void DFS(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &isl, pair<int, int> &base) {
        int n = grid.size(), m = grid[0].size();
        vis[i][j] = 1;
        isl.push_back({i - base.first, j - base.second});
        for (int k = 0; k < 4; k++) {
            int x = i + dirX[k];
            int y = j + dirY[k];
            if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == 1) {
                DFS(x, y, grid, vis, isl, base);
            }
        }
    }

  public:
    int countDistinctIslands(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        set<vector<pair<int, int>>> islands;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> isl;
                    pair<int, int> base = {i, j};
                    DFS(i, j, grid, vis, isl, base);
                    islands.insert(isl);
                }
            }
        }
        return islands.size();
    }
};
