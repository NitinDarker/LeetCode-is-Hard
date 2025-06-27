// https://leetcode.com/problems/coin-change-ii/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int i, int target, vector<vector<int>> &dp, vector<int> &coins) {
        if (dp[i][target] != -1) return dp[i][target];
        if (i == 0) {
            if (target == 0) return 1; // not Take
            if (target % coins[0] == 0) return dp[i][target] = 1; // Take
            return dp[i][target] = 0; 
        }
        int notTake = f(i-1, target, dp, coins);
        int take = 0;
        if (coins[i] <= target) take = f(i, target-coins[i], dp, coins);
        return dp[i][target] = take + notTake;
    }

  public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(n-1, amount, dp, coins);
    }
};


// Tabulation -> Overflow on LeetCode
class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1, 0));

        dp[0][0] = 1;
        for (int j = coins[0]; j <= amount; j++) dp[0][j] = dp[0][j - coins[0]];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                long long notTake = dp[i-1][j];
                long long take = 0;
                if (coins[i] <= j) take = dp[i][j-coins[i]];
                dp[i][j] = take + notTake;
                if (dp[i][j] > 1e10) dp[i][j] = 0;
            }
        }
        return dp[n-1][amount];
    }
};
