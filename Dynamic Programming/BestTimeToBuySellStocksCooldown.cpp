/// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int ind, bool buy, vector<vector<int>> &dp, const vector<int> &prices) {
        if (ind >= prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy) {
            int take = -prices[ind] + f(ind + 1, 0, dp, prices);
            int notTake = f(ind + 1, 1, dp, prices);
            profit = max(take, notTake);
        } else {
            int sell = prices[ind] + f(ind + 2, 1, dp, prices);
            int notSell = f(ind + 1, 0, dp, prices);
            profit = max(sell, notSell);
        }
        return dp[ind][buy] = profit;
    }

  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, dp, prices);
    }
};

// Tabulation
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                int profit = 0;
                if (j == 1) {
                    int take = -prices[i] + dp[i + 1][0];
                    int notTake = dp[i + 1][1];
                    profit = max(take, notTake);
                } else {
                    int sell = prices[i] + dp[i + 2][1];
                    int notSell = dp[i + 1][0];
                    profit = max(sell, notSell);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};
