// https://leetcode.com/problems/last-day-where-you-can-still-cross/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int row, int col, vector<vector<int>> &vis) {
        int rows = vis.size(), cols = vis[0].size();
        if (row == rows-1) return true;
        if (vis[row][col] == 1) return false;
        vis[row][col] = 1;
        if (row > 0 && !vis[row-1][col] && dfs(row-1, col, vis)) return true;
        if (row < rows-1 && !vis[row+1][col] && dfs(row+1, col, vis)) return true;
        if (col > 0 && !vis[row][col-1] && dfs(row, col-1, vis)) return true;
        if (col < cols-1 && !vis[row][col+1] && dfs(row, col+1, vis)) return true;
        return false;
    }

public:
    int latestDayToCross(int rows, int cols, vector<vector<int>>& cells) {
        int days = cells.size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int l = 0, r = days;
        int latestDay = 0;
        while (l <= r) {
            int mid = l + (r-l)/2;

            for (int i = 0; i < mid; i++) {
                int row = cells[i][0]-1, col = cells[i][1]-1;
                vis[row][col] = 1;
            }

            bool found = false;
            for (int i = 0; i < cols; i++) {
                if (dfs(0, i, vis)) {
                    found = true;
                    break;
                }
            }

            if (found) {
                latestDay = max(latestDay, mid);
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    vis[i][j] = 0;
                }
            }
        }
        return latestDay;
    }
};
