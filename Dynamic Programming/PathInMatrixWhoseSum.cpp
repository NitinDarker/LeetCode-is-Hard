// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
    long long f(int i, int j, int sum, vector<vector<int>> &grid, vector<vector<vector<long long>>> &dp, int k) {
        int m = grid.size(), n = grid[0].size();
        if (dp[i][j][sum] != -1)
            return dp[i][j][sum];
        if (i == m - 1 && j == n - 1) {
            sum = (sum + grid[i][j]) % k;
            if (sum % k == 0) {
                return 1;
            }
            return 0;
        }
        long long down = 0, right = 0;
        if (i < m - 1) {
            down = f(i + 1, j, (sum + grid[i][j]) % k, grid, dp, k);
        }
        if (j < n - 1) {
            right = f(i, j + 1, (sum + grid[i][j]) % k, grid, dp, k);
        }
        return dp[i][j][sum] = (down + right) % MOD;
    }

  public:
    int numberOfPaths(vector<vector<int>> &grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(k, -1)));
        return f(0, 0, 0, grid, dp, k);
    }
};
