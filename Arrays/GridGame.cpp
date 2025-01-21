// 2017. Grid Game -> LeetCode Daily Problem (Medium)

// You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. 
// Two robots are playing a game on this matrix.
// Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).
// At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path.
// For all cells (r, c) traversed on the path, grid[r][c] is set to 0.
// Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.
// The first robot wants to minimize the number of points collected by the second robot. 
// In contrast, the second robot wants to maximize the number of points it collects. 
// If both robots play optimally, return the number of points collected by the second robot.

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefix1(n), prefix2(n);
        prefix1[0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            prefix1[i] = (long long) prefix1[i-1] + (long long)grid[0][i];
        }
        prefix2[0] = grid[1][0];
        for (int i = 1; i < n; i++) {
            prefix2[i] = (long long) prefix2[i-1] + (long long) grid[1][i];
        }
        long long maxi = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long top = 0, bottom = 0;
            top = prefix1[n-1] - prefix1[i];
            if (i != 0) bottom = prefix2[i-1];
            long long currPoints = max(top, bottom);
            maxi = min(maxi, currPoints);
        }
        return maxi;
    }
};
