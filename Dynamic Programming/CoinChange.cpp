// https://leetcode.com/problems/coin-change/description/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if (dp[i][amount] != -1) return dp[i][amount];
        if (i == 0) {
            if (amount == 0) return 0;
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }
        int notPick = 0 + f(i-1, amount, coins, dp);
        int pick = INT_MAX;
        if (coins[i] <= amount) pick = 1 + f(i, amount-coins[i], coins, dp);
        return dp[i][amount] = min(pick, notPick);
    }

  public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = f(n-1, amount, coins, dp);
        if (ans >= 1e9) return -1;
        return ans;
    }
};


// Tabulation
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) dp[0][j] = j / coins[0];
            else dp[0][j] = 1e9;
        }
        

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int notPick = 0 + dp[i-1][j];
                int pick = 1e9;
                if (coins[i] <= j) pick = 1 + dp[i][j-coins[i]];
                dp[i][j] = min(pick, notPick);
            }
        }
        int res = dp[n-1][amount];
        if (res >= 1e9) {
            return -1;
        }
        return res;
    }
};
