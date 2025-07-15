// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int ind, bool buy, vector<vector<int>> &dp, const vector<int> &prices, int fee) {
        if (ind == prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy) {
            int take = -prices[ind] + f(ind + 1, 0, dp, prices, fee);
            int notTake = f(ind + 1, 1, dp, prices, fee);
            profit = max(take, notTake);
        } else {
            int sell = prices[ind] - fee + f(ind + 1, 1, dp, prices, fee);
            int notSell = f(ind + 1, 0, dp, prices, fee);
            profit = max(sell, notSell);
        }
        return dp[ind][buy] = profit;
    }

  public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, dp, prices, fee);
    }
};

// Tabulation
class Solution {
  public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                int profit = 0;
                if (j == 1) {
                    int take = -prices[i] + dp[i + 1][0];
                    int notTake = dp[i + 1][1];
                    profit = max(take, notTake);
                } else {
                    int sell = prices[i] - fee + dp[i + 1][1];
                    int notSell = dp[i + 1][0];
                    profit = max(sell, notSell);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};

// Space Optimization
class Solution {
  public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        int nextBuy = 0, nextNotBuy = 0;
        for (int i = n - 1; i >= 0; i--) {
            int take = -prices[i] + nextNotBuy;
            int notTake = nextBuy;
            int currBuy = max(take, notTake);

            int sell = prices[i] - fee + nextBuy;
            int notSell = nextNotBuy;
            int currNotBuy = max(sell, notSell);
            nextBuy = currBuy;

            nextNotBuy = currNotBuy;
        }
        return nextBuy;
    }
};
