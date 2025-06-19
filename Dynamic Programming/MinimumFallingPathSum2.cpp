// https://leetcode.com/problems/minimum-falling-path-sum/description/
#include <bits/stdc++.h>
using namespace std;

// Tabulation
class Solution {
  public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                int mini = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;
                    mini = min(mini, matrix[i][j] + dp[i - 1][k]);
                }
                dp[i][j] = mini;
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(dp[n-1][j], mini);
        }
        return mini;
    }
};

// Space Optmizatino
class Solution {
  public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return matrix[0][0];

        for (int i = 1; i < n; i++) {
            int min1 = INT_MAX; // Mininum from previous row
            int min2 = INT_MAX; // Second min from previous row
            int idx1 = -1;      // Index of min1

            for (int k = 0; k < n; k++) {
                if (matrix[i - 1][k] < min1) {
                    min2 = min1;
                    min1 = matrix[i - 1][k];
                    idx1 = k;
                } else if (matrix[i - 1][k] < min2) {
                    min2 = matrix[i - 1][k];
                }
            }

            for (int j = 0; j < n; j++) {
                int sum_from_prev;
                if (j == idx1) {
                    sum_from_prev = min2;
                } else {
                    sum_from_prev = min1;
                }
                matrix[i][j] = matrix[i][j] + sum_from_prev;
            }
        }

        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, matrix[n - 1][j]);
        }
        return mini;
    }
};
