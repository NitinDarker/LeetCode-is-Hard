// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<int> dx = {1, 0, -1, 0};
    const vector<int> dy = {0, 1, 0, -1};
    
    void dfs(int x, int y, vector<vector<bool>> &vis, const vector<vector<int>> &grid, set<pair<int,int>> &arr, const pair<int,int> &base) {
        int n = grid.size(), m = grid[0].size();
        if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || grid[x][y] == 0) return;
        vis[x][y] = 1;
        int i = x-base.first, j = y-base.second;
        arr.insert({i, j});
        for (int i = 0; i < 4; i++) dfs(x+dx[i], y+dy[i], vis, grid, arr, base);
    }
    
    public:
    int countDistinctIslands(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        set<set<pair<int,int>>> isl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    set<pair<int,int>> arr;
                    pair<int,int> base = {i, j};
                    dfs(i, j, vis, grid, arr, base);
                    isl.insert(arr);
                }
            }
        }
        return isl.size();
    }
};
