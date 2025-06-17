// https://leetcode.com/problems/minimum-falling-path-sum/description/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int i, int j, vector<vector<int>> &dp, const vector<vector<int>> &matrix) {
        if (dp[i][j] != -1000) {
            return dp[i][j];
        }
        if (i == 0) {
            return matrix[i][j];
        }
        int n = matrix.size();
        int up = f(i-1, j, dp, matrix);
        int ld = INT_MAX, rd = INT_MAX;
        if (j != 0) ld = f(i-1, j-1, dp, matrix);
        if (j != n-1) rd = f(i-1, j+1, dp, matrix);
        return dp[i][j] = matrix[i][j] + min(min(up, ld), rd);
    }


  public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1000));
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(f(n-1, j, dp, matrix), mini);
        }
        return mini;
    }
};

// Tabulation
class Solution {
  public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1000));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                int up = dp[i-1][j];
                int ld = INT_MAX, rd = INT_MAX;
                if (j != 0) ld = dp[i-1][j-1];
                if (j != n-1) rd = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min(min(up, ld), rd);
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(dp[n-1][j], mini);
        }
        return mini;
    }
};

// Space Optimization
class Solution {
  public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i-1][j];
                int ld = INT_MAX, rd = INT_MAX;
                if (j != 0) ld = matrix[i-1][j-1];
                if (j != n-1) rd = matrix[i-1][j+1];
                matrix[i][j] += min(min(up, ld), rd);
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(matrix[n-1][j], mini);
        }
        return mini;
    }
};
