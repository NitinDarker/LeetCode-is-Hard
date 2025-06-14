// https://leetcode.com/problems/unique-paths/description/
#include <bits/stdc++.h>
using namespace std;

// Memoization -> Recursive
class Solution {
    int dpHelper(int m, int n, vector<vector<int>> &dp) {
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = dpHelper(m-1, n, dp) + dpHelper(m, n-1, dp);
    }

  public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dpHelper(m-1, n-1, dp);
    }
};


// Tabulation
class Solution2 {
  public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};


// Space Optimization
class Solution2 {
  public:
    int uniquePaths(int m, int n) {
        vector<int> up(n, 0);
        for (int i = 0; i < m; i++) {
            int left = 0;
            for (int j = 0; j < n; j++) {
                int curr = up[j] + left;
                if (i == 0 && j == 0)
                    curr = 1;
                left = curr;
                up[j] = curr;
            }
        }
        return up[n - 1];
    }
};
