// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    int f(int i, int j, int k, vector<vector<int>> &coins, vector<vector<vector<int>>> &dp) {
        if (dp[i][j][k] != -1e9) return dp[i][j][k];
        int m = coins.size(), n = coins[0].size();

        // Base Case -> Bottom Right Cell
        if (i == m-1 && j == n-1) {
            if (coins[i][j] < 0 && k > 0) return dp[i][j][k] = 0;
            return dp[i][j][k] = coins[i][j];
        }

        // Positive Coins
        if (coins[i][j] >= 0) {
            int bottom = -1e9, right = -1e9;
            if (i < m-1) bottom = f(i+1, j, k, coins, dp);
            if (j < n-1) right = f(i, j+1, k, coins, dp);
            return dp[i][j][k] = max(bottom, right) + coins[i][j];
        }

        // Negative Coins
        if (k > 0) {
            // Neutralize
            int bottomNeu = -1e9, rightNeu = -1e9;
            if (i < m-1) bottomNeu = f(i+1, j, k-1, coins, dp);
            if (j < n-1) rightNeu = f(i, j+1, k-1, coins, dp);
            int neut = max(bottomNeu, rightNeu) + 0;

            // Take the Loss
            int bottomLoss = -1e9, rightLoss = -1e9;
            if (i < m-1) bottomLoss = f(i+1, j, k, coins, dp);
            if (j < n-1) rightLoss = f(i, j+1, k, coins, dp);
            int loss = max(bottomLoss, rightLoss) + coins[i][j]; 

            return dp[i][j][k] = max(neut, loss);
        } 
        else {
            // Take the Loss
            int bottomLoss = -1e9, rightLoss = -1e9;
            if (i < m-1) bottomLoss = f(i+1, j, k, coins, dp);
            if (j < n-1) rightLoss = f(i, j+1, k, coins, dp);
            return dp[i][j][k] = max(bottomLoss, rightLoss) + coins[i][j];
        }
    }

  public:
    int maximumAmount(vector<vector<int>> &coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (3, -1e9)));
        return f(0, 0, 2, coins, dp);
    }
};
