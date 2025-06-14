// https://leetcode.com/problems/unique-paths-ii/description/
#include <bits/stdc++.h>
using namespace std;

// Tabulation
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        long long dp[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j-1];
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};


// Space Optimization
class Solution2 {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long long> up(n, 0);
        for (int i = 0; i < m; i++) {
            long long left = 0;
            for (int j = 0; j < n; j++) {
                long long curr = up[j] + left;
                if (i == 0 && j == 0) curr = 1;
                if (obstacleGrid[i][j] == 1) curr = 0;
                left = curr;
                up[j] = curr;
            }
        }
        return up[n - 1];
    }
};
